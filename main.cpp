//
//  main.cpp
//  Guitar strings
//
//  Created by dongho on 2020/02/25.
//  Copyright © 2020 dongho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class GuitarString{
    vector<vector<int> > brand;
    int cutNum, brandNum;
    
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
            brand.at(i).push_back(findBMin(i));
            
        }
    }
    int findBMin(int i){
        int min;
        int bundleEa, bundle, ea;
        bundleEa = (cutNum/6 * brand.at(i).at(0) + ((cutNum % 6) * brand.at(i).at(1)));
        
        ea = cutNum * brand.at(i).at(1);
        
        bundle = (cutNum/6+1)*brand.at(i).at(0);
        
        
        
        if(bundleEa < ea){
            if(bundleEa < bundle)
                min = bundleEa;
            else
                min = bundle;
        }
        else{
            if(ea < bundle)
                min = ea;
            else
                min = bundle;
        }
        
        return min;
    }
    
    //브랜드의 최소값끼리 비교하기
    void searchMin(){
        int Min = brand.at(0).at(2);
        for(int i=1; i<brandNum; i++){
            if(brand.at(i).at(2) < Min)
                Min = brand.at(i).at(2);
        }
        cout << Min;
    }
    
};

int main() {
    int cutNum, brandNum;
    cin >> cutNum >> brandNum;
    
    GuitarString g(cutNum, brandNum);
    g.searchMin();
}
