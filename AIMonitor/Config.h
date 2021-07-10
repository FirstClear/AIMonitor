#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
class Config
{
public:
	//���幹�캯��
	Config(string file);
	void setConfig();
	void setUser(string & user);
	string getUser();
	void setPassword(string & password);
	string getPassword();
	void setChannel(string & channel);
	vector<int> getChannel();
	void setLocation(string & location);
	string getLocation();
	void setSending(string & sending);
	string getSending();
	void setDuring(string & during);
	string getDuring();
	void setVersion(string & version);
	string getVersion();
	void setId(string & id);
	string getId();
	void printConfig();
	string file="file";//�ļ�·��
	string id="id";  //����id
	string username="username"; //�ۺ�ϵͳ�û���
	string password="password"; //�ۺ�ϵͳ����
	string channel="channel";//ѡ���ͨ������Ϊȫѡ
	string location="location";//���ӵ�ַ��http://pm.cscec81.com/
	string sending="sending";//�Ƿ�����Ϣ
	string during="during";//���ͼ��
	string version="version";//�汾��
private:
	map<string, int> hasAttribute;//�ж��Ƿ����������
	map<string, string> attributes;   //����
};

