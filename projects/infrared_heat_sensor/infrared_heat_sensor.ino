int IRswitch = 8; //热释电红外传感器信号输出端；
int led = 13; //信号指示灯输入；
boolean val = false; //读取传感器实时信号；
void setup()
{
pinMode(IRswitch,INPUT);
pinMode(led,OUTPUT); //定义端口属性；
}
void loop()
{
val = digitalRead(IRswitch); //读取传感器输出电平高低；
if(val)
  digitalWrite(led,HIGH); //有人在监测范围内活动，灯亮；
else
  digitalWrite(led,LOW); //一切正常，灯灭；
delay(10); //稍作延时，让 led 状态稳定；
}
