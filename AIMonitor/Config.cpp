#pragma once

#include <iostream>
#include "Config.h"
#include <string>
#include <fstream>
#include <regex>
#define ToString(x) #x
using namespace std;
/*
Time:2021-06-08 17:20:00
Creator:whl
Discription:正则分割字符串方法，str:源字符串，v:接受分割后字符串的容器，tag:分割标识，返回分割后字符串的个数
return:int
*/
int split(string str, vector<string> &v, string tag = " ") {
	//拼接正则表达式
	string reStr = "[^" + tag + "]+";
	//构建正则对象
	regex re(reStr);
	//获取指向字符串开头的正则迭代器
	sregex_iterator word_begin = sregex_iterator(str.begin(), str.end(), re);
	//获取指向结尾的迭代器
	sregex_iterator word_end = sregex_iterator();
	for (auto i = word_begin; i != word_end; i++) {
		v.push_back((*i).str());
	}
	//返回分割后字符串的个数
	return distance(word_begin, word_end);
}
/*
Time:2021-06-15 15:37:47
Creator:whl
Discription:Config配置文件类
constructor:构造函数包含一个string类型的文件路径，文件格式必须是不含有其他字符的单行键值对。
private：私有成员包含两个属性：hasAttribute以及attributes，hasAttribute表示是否拥有某一配置，attributes是一个string，string类型的map，存放键值对。
set，get method：
*/
Config::Config(string filepath)
{
	
	hasAttribute[id] = 1;
	hasAttribute[username] = 1;
	hasAttribute[password] = 1;
	hasAttribute[channel] = 1;
	hasAttribute[location] = 1;
	hasAttribute[sending] = 1;
	hasAttribute[during] = 1;
	hasAttribute[version] = 1;
	Config::file = filepath;
	ifstream in(filepath, ios::in);
	string line;
	vector<string> lines;
	if (in.fail())
	{
		cout << "open file error" << endl;
	}
	//逐行判断是否存在属性，如果存在，就读入，不存在就跳过
	while (getline(in, line))
	{
		split(line, lines, "=");

		if (hasAttribute.find(lines[0]) != hasAttribute.end()) {
			if (lines.size() > 1) 
			{
				attributes[lines[0]] = lines[1];
			}
			else if(lines.size()==1)
			{
				attributes[lines[0]] = "";
			}
		}
		lines.clear();
	}
	in.close();
}
void Config::setConfig() {
	ofstream out(file,ios::out);
	if (out.fail()) {
		cout << "error\n";
	}

	string line;
	for (auto iter = attributes.begin();iter != attributes.end();iter++) {
		line = iter->first + "=" + iter->second;
		out << line << endl;
	}
	out.flush();
	out.close();
}
void Config::setUser(string& username) {
	this->attributes[this->username] = username;
}
string Config::getUser() {
	return this->attributes[this->username];
}
void Config::setPassword(string& password) {
	this->attributes[this->password] = password;
}
string Config::getPassword() {
	return this->attributes[this->password];
}
void Config::setChannel(string& channel) {
	this->attributes[this->channel] = channel;
}
vector<int> Config::getChannel() {
	vector<string> v;
	split(this->attributes[this->channel],v,",");
	vector<int> res;
	for (int i = 0;i < v.size();i++) {
		int intStr = atoi(v[i].c_str());
		res.push_back(intStr);
	}
	return res;
}
void Config::setLocation(string& location) {
	this->attributes[this->location] = location;
}
string Config::getLocation() {
	return this->attributes[this->location];
}
void Config::setSending(string& sending) {
	this->attributes[this->sending] = sending;
}
string Config::getSending() {
	return this->attributes[this->sending];
}
void Config::setDuring(string& during) {
	this->attributes[this->during] = during;
}
string Config::getDuring() {
	return this->attributes[this->during];
}
void Config::setVersion(string& version) {
	this->attributes[this->version] = version;
}
string Config::getVersion() {
	return this->attributes[this->version];
}
void Config::setId(string& id) {
	this->attributes[this->id] = id;
}
string Config::getId() {
	return this->attributes[this->id];
}
void Config::printConfig() {
	cout <<this->id<<":"<< this->getId() << endl;
	cout <<this->location<<":"<< this->getLocation()<<endl;
	cout <<this->username<<":"<<this->getUser() << endl;
	cout << this->password<<":"<<this->getPassword() << endl;
	cout << this->sending<<":"<<this->getSending() << endl;
	cout << this->during<<":"<< this->getDuring() << endl;
	cout << this->version<<":"<<this->getVersion() << endl;
	cout << this->channel << ":" << this->attributes[this->channel] << endl;
}