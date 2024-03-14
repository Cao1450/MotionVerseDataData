// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include <iostream>
#include<vector>
#include<string>
#include <chrono>

using namespace std;

/**
 * 
 */
class MVUTILSTOOLS_API Sha1
{
public:
	Sha1();
	~Sha1();

    //获取时间戳
    static long long getUnix();
    //获取时间戳字符串
    static string getUnixStr();
    //sha1
    static string sha1(string text);
    static string GetSha1(string appid, string secret, string timestamp = "");


private:
    //文本的填充处理
    static void append(string m, int& Turn, vector<int>& X);
    static void setW(vector<int> m, int n, int W[80], vector<int>& X);
    //循环左移
    static int S(unsigned int x, int n, vector<int>& X);
    //ft(B,C,D)函数
    static int ft(int t, int& B, int& C, int& D);
    //常量K
    static int Kt(int t);

    static string format(const char* fmt, ...);
};
