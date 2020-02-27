//
//  main.cpp
//  Guitar strings
//
//  Created by dongho on 2020/02/25.
//  Copyright © 2020 dongho. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class GuitarString{
    vector<vector<int> > brand;
    int cutNum, brandNum;
    int MinB, MinE;
public:
    GuitarString(int c, int b){
        cutNum = c;
        brandNum = b;
        //브랜드 수만큼 늘려주기
        int temp1, temp2;
        for(int i=0; i<brandNum; i++){
            brand.push_back(vector<int>());
            
            cin >> temp1 >> temp2;
            brand.at(i).push_back(temp1);
            brand.at(i).push_back(temp2);
        }
    }
    //필요한 기타줄의 개수가 6의 배수인지 확인
    bool IsMultipleOfSix(){
        if((cutNum % 6) == 0)
            return true;
        else
            return false;
    }
    
    //묶음의 최소값과 낱개의 최소값 셋팅하기
    void settingMin(){
        MinB = brand.at(0).at(0);
        MinE = brand.at(0).at(1);
        for(int i=1; i<brand.size(); i++){
            if(brand.at(i).at(0) < MinB)
                MinB = brand.at(i).at(0);
            if(brand.at(i).at(1) < MinE)
                MinE = brand.at(i).at(1);
        }
    }
    
    //효율적인 구매비용 구하기
    int Cost(){
        int Bundle, Ea, BundleEa, OverBundle;
        settingMin();
        
        Bundle = MinB * (cutNum / 6);
        Ea = MinE * cutNum;
        BundleEa = MinB * (cutNum / 6) + MinE * (cutNum % 6);
        OverBundle = MinB * (cutNum/6 + 1);
        
        if(IsMultipleOfSix() == true){
            if(Bundle < Ea)
                return Bundle;
            else
                return Ea;
        }
        else{
            if(cutNum < 6){
                if(MinB < Ea)
                    return MinB;
                else
                    return Ea;
            }
            if(BundleEa< OverBundle){
                if(BundleEa < Ea)
                    return BundleEa;
                else{
                    if(Ea < OverBundle)
                        return Ea;
                    else
                        return OverBundle;
                }
            }
            else{
                if(OverBundle < Ea)
                    return OverBundle;
                else{
                    if(Ea < BundleEa)
                        return Ea;
                    else
                        return BundleEa;
                }

            }
        }
    }
};

int main() {
    int cutNum, brandNum;
    cin >> cutNum >> brandNum;
    
    GuitarString g(cutNum, brandNum);
    cout << g.Cost();
}
