//
// Created by brok1n on 2016/6/21.
//

#include "bcalculator.h"

#include <ctype.h>
#include <stdlib.h>


Bcalculator::Bcalculator() {
    mTmpNumberIndex = 0;
    mCircleIndex = 0;
}

Bcalculator::~Bcalculator() {

}

int Bcalculator::pressed(char ch) {

    //
    if( isdigit( ch ) || ch == '.'  )
    {
        if( mTmpNumberIndex == 0 && ch == '.' )
            mTmpNumber[mTmpNumberIndex++] = '0';
        mTmpNumber[mTmpNumberIndex++] = ch;
        return 1;
    }

    switch ( ch )
    {
        case '+':
            if( mTmpNumberIndex == 0 )
            {
                return 0;
            }
            else
            {
                mTmpNumber[mTmpNumberIndex++] = '\0';
                char *pEnd;
                mValue[mCircleIndex] = strtod( mTmpNumber, &pEnd);
                mOperator[mCircleIndex] = ch;
                mCircleIndex++;
                mTmpNumberIndex = 0;
                return 1;
            }
            break;
        case '-':
            if( mTmpNumberIndex == 0 )
            {
                mTmpNumber[mTmpNumberIndex++] = ch;
                return 1;
            }
            else
            {
                mTmpNumber[mTmpNumberIndex++] = '\0';
                char *pEnd;
                mValue[mCircleIndex] = strtod( mTmpNumber, &pEnd);
                mOperator[mCircleIndex] = ch;
                mCircleIndex++;
                mTmpNumberIndex = 0;
                return 1;
            }
            break;
        case '*':
            if( mTmpNumberIndex == 0 )
            {
                return 0;
            }
            else
            {
                mTmpNumber[mTmpNumberIndex++] = '\0';
                char *pEnd;
                mValue[mCircleIndex] = strtod( mTmpNumber, &pEnd);
                mOperator[mCircleIndex] = ch;
                mCircleIndex++;
                mTmpNumberIndex = 0;
                return 1;
            }
            break;
        case '/':
            if( mTmpNumberIndex == 0 )
            {
                return 0;
            }
            else
            {
                mTmpNumber[mTmpNumberIndex++] = '\0';
                char *pEnd;
                mValue[mCircleIndex] = strtod( mTmpNumber, &pEnd);
                mOperator[mCircleIndex] = ch;
                mCircleIndex++;
                mTmpNumberIndex = 0;
                return 1;
            }
            break;
        case '=':
            if( mTmpNumberIndex == 0 )
            {
                return 0;
            }
            else
            {
                mTmpNumber[mTmpNumberIndex++] = '\0';
                char *pEnd;
                mValue[mCircleIndex] = strtod( mTmpNumber, &pEnd);
                mOperator[mCircleIndex] = ch;
                mCircleIndex++;
                mTmpNumberIndex = 0;
                return 1;
            }
            break;
        default:
            break;
    }


    return 0;
}

double Bcalculator::count() {

    int index = 0;
    for (int j = 0; j < mCircleIndex; ++j) {
        char currentOperator = mOperator[j];
        char nextOperator = mOperator[j + 1];

        switch (currentOperator)
        {
            case '*':
                mValue[j] = mValue[j] * mValue[j+1];
                mCircleIndex--;
                for (int i = j +1; i < mCircleIndex ; ++i) {
                    mValue[i] = mValue[i+1];
                    mOperator[i-1] = mOperator[i];
                }
                break;
            case '/':
                mValue[j] = mValue[j] / mValue[j+1];
                mCircleIndex--;
                for (int i = j +1; i < mCircleIndex ; ++i) {
                    mValue[i] = mValue[i+1];
                    mOperator[i-1] = mOperator[i];
                }
                break;
            default:
                break;
        }
    }
    mOperator[mCircleIndex-1] = '=';

    double result = mValue[0];
    for (int k = 0; k < mCircleIndex; ++k) {
        char currentOperator = mOperator[k];
        if( currentOperator == '+' )
        {
            result += mValue[k+1];
        }
        else if( currentOperator == '-' )
        {
            result -= mValue[k+1];
        }
    }
    return result;
}


