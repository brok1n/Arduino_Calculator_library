//
// Created by brok1n on 2016/6/21.
//

#ifndef BROK1N_BCALCULATOR_H
#define BROK1N_BCALCULATOR_H


class Bcalculator
{
public:
    Bcalculator();
    ~Bcalculator();

private:
    char mTmpNumber[11];    //输入的操作数 float类型4字节  32位 最大可表示 4294967295 四十多亿 十位数字
    int  mTmpNumberIndex;   //临时数字的字符是输入的第几个
    double mValue[16];       //要参与运算的数字
    int mCircleIndex;       //运算数第几个
    char  mOperator[64];    //要参与运算的操作符

public:
    int pressed( char ch ); //计算器按下一个键
    double count();         //得到运算结果
	

};

#endif //BROK1N_BCALCULATOR_H
