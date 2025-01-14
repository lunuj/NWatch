#include "configWiFi.h"

Preferences prefs;
DNSServer dnsServer;  // 创建dnsServer实例
WebServer server(80); // 开启web服务, 创建TCP SERVER,参数: 端口号,最大连接数
IPAddress apIP(192, 168, 4, 1);
const byte DNS_PORT = 53; // 设置DNS端口号
ConfigWiFi::~ConfigWiFi() {}
ConfigWiFi::ConfigWiFi() : wifiEnabled(false) {}

void InitWiFi()
{
    prefs.begin("WiFiAP");                   // 在Preferences中命名空间和键名均为字符串，并且长度不大于15个字节 大于可能无法打开命名空间
    WiFi_Name = prefs.getString("WiFiName"); // wifi名字
    WiFi_Pass = prefs.getString("WiFiPass"); // wifi密码
    WiFi_LOG("WiFi N:%s WiFi P:%s", WiFi_Name, WiFi_Pass);
    prefs.end();
}

void FunctionRoot()
{
    server.send(200, "text/html", ROOT_HTML);
}

void setWiFi(String w, String p)
{
    prefs.begin("WiFiAP");
    prefs.putString("WiFiName", w); // 默认值
    prefs.putString("WiFiPass", p); // 默认值
    WiFi_Name = prefs.getString("WiFiName");
    WiFi_Pass = prefs.getString("WiFiPass");
    WiFi_LOG("WiFi N:%s \nWiFi P:%s \n", WiFi_Name, WiFi_Pass);
    prefs.end();
}

void handleConfigWifi() // 返回http状态
{
    if (server.hasArg("ssid") && server.hasArg("password")) // 判断是否有账号参数
    {
        WiFi_Name = server.arg("ssid");     // 获取html表单输入框name名为"ssid"的内容
        WiFi_Pass = server.arg("password"); // 获取html表单输入框name名为"pwd"的内容
        setWiFi(WiFi_Name, WiFi_Pass);
        server.send(200, "text", "ture");
    }
    else
    {                                                                                 // 没有参数
        server.send(200, "text/html", "<meta charset='UTF-8'>error, not found ssid"); // 返回错误页面
        return;
    }
    server.send(200, "text/html", "<meta charset='UTF-8'>SSID：" + WiFi_Name + "<br />password:" + WiFi_Pass + "<br />已取得WiFi信息,正在尝试连接,请手动关闭此页面。"); // 返回保存成功页面
    // WiFi.softAPdisconnect(true);     //参数设置为true，设备将直接关闭接入点模式，即关闭设备所建立的WiFi网络。
    // server.close();                  //关闭web服务
    // WiFi.softAPdisconnect();         //在不输入参数的情况下调用该函数,将关闭接入点模式,并将当前配置的AP热点网络名和密码设置为空值.
}

void scanWiFi()
{
    WiFi.disconnect();
    static String req_json = "";
    int n = WiFi.scanNetworks();
    int m = 0;
    if (n > 0)
    {
        req_json = "{\"req\":[";
        for (int i = 0; i < n; i++)
        {
            if ((int)WiFi.RSSI(i) >= -200)
                //  if (1) {
                m++;
            String a = "{\"ssid\":\"" + (String)WiFi.SSID(i) + "\"," + "\"encryptionType\":\"" + WiFi.encryptionType(i) + "\"," + "\"rssi\":" + (int)WiFi.RSSI(i) + "},";
            if (a.length() > 15)
                req_json += a;
        }
    }
    req_json.remove(req_json.length() - 1);
    req_json += "]}";
    server.send(200, "text/json;charset=UTF-8", req_json);
    WiFi_LOG("req_json:%s\n", req_json.c_str());
}

void ConfigWiFi::APMode()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        WiFi.mode(WIFI_OFF);
    }
    WiFi.mode(WIFI_AP_STA);                                     // 配置为AP模式
    WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0)); // 设置AP热点IP和子网掩码
    WiFi.softAP(AP_SSID);
    dnsServer.start(DNS_PORT, "*", apIP); // 判断将所有地址映射到esp32的ip上是否成功
    MDNS.begin("Chappie");
    // 必须添加第二个参数HTTP_GET，以下面这种格式去写，否则无法强制门户
    server.on("/", HTTP_GET, FunctionRoot);     //  当浏览器请求服务器根目录(网站首页)时调用自定义函数handleRoot处理，设置主页回调函数，必须添加第二个参数HTTP_GET，否则无法强制门户
    server.on("/configwifi", handleConfigWifi); //  当浏览器请求服务器/configwifi(表单字段)目录时调用自定义函数handleConfigWifi处
    server.on("/scanWiFi", scanWiFi);
    server.onNotFound(FunctionRoot); // 当浏览器请求的网络资源无法在服务器找到时调用自定义函数handleNotFound处理
    server.begin();                  // 启动TCP SERVER
    OnAP = true;

    // return true;
}

const char *ConfigWiFi::WiFiN()
{
    return WiFi_Name.c_str();
}

void ConfigWiFi::Init()
{
    WiFi.softAPsetHostname(HOST_NAME);
    InitWiFi();
    WiFi.mode(WIFI_STA);
}

bool ConfigWiFi::APClose()
{
    server.close();
    dnsServer.stop();
    WiFi.softAPdisconnect(true);
    WiFi.mode(WIFI_OFF);
    OnAP = false;
    return true;
}

void ConfigWiFi::enableWiFi()
{
    if (isConnected())
    {
        WiFi_LOG("WiFi已经是启用状态");
        return;
    }
    else
    {
        wifiEnabled = true;
        WiFi.begin(WiFi_Name.c_str(), WiFi_Pass.c_str());
    }
}

void ConfigWiFi::disableWiFi()
{
    if (wifiEnabled)
    {
        wifiEnabled = false;
        WiFi.disconnect(); // 断开 WiFi 连接
        WiFi.mode(WIFI_OFF);
    }
    else
    {
        WiFi_LOG("WiFi已经是禁用状态");
    }
}
bool ConfigWiFi::enableIPv6()
{
    return WiFi.enableIpV6();
}
bool ConfigWiFi::isWiFiEnabled() const
{
    return wifiEnabled;
}
bool ConfigWiFi::isConnected() const
{
    return (WiFi.status() == WL_CONNECTED);
}
String ConfigWiFi::LocalIP()
{
    return (WiFi.status() == WL_CONNECTED) ? (WiFi.localIP().toString().c_str()) : "0.0.0.0";
}
String ConfigWiFi::GateWay()
{
    // printf("GYIP:%s",WiFi.gatewayIP().toString().c_str());
    return (WiFi.status() == WL_CONNECTED) ? WiFi.gatewayIP().toString() : "0.0.0.0";
}
const char *ConfigWiFi::WiFiMac()
{
    return (WiFi.status() == WL_CONNECTED) ? WiFi.macAddress().c_str() : "None";
}

void ConfigWiFi::WiFiloop()
{
    if (OnAP)
    {
        server.handleClient();
        dnsServer.processNextRequest();        
        delay(10);
    }
}

String ConfigWiFi::GetIPv6()
{
    return (WiFi.status() == WL_CONNECTED) ? (WiFi.localIPv6().toString()) : "0:0:0:0";
}