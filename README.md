# GuitarString
백준 1049번 문제 풀이입니다.

문제 : 기타줄을 사야하는데 가장 싼 가격으로 사야한다.
# 전략
* 필요한 기타줄의 수가 6으로 나누어 떨어지는 것과 아닌 것을 비교한다.
    * 6으로 나누어 떨어질 때 : 묶음가격과 낱개가격의 최소비용만 비교하면됨.
    * 6으로 나누어 떨어지지 않을 때 : 묶음가격, 낱개가격, 묶음+낱개 가격 세개를 비교해야한다.
* 필요한 기타줄의 수가 6보다 적을 때는 예외처리를 한다.
* 나누어 떨어지지 않을 때의 묶음 가격은 나누어 떨어질때보다 1개 더 많게 설정한다.

# GuitarString class

## 생성자 GuitarString
```c++
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
```
필요한 기타줄 수와 브랜드 수를 입력받아서 2차원 벡터 brand에 값을 넣어준다.

## 함수 IsMultipleOfSix
```c++
    bool IsMultipleOfSix(){
        if((cutNum % 6) == 0)
            return true;
        else
            return false;
    }

```
6으로 나누어 떨어지는 지 검사
## 함수 settingMin
```c++
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
```
MinB : 브랜드 전체 중에서 묶음 가격이 가장 싼 가격\
MinE : 브랜드 전체 중에서 낱개 가격이 가장 싼 가격

## 함수 Cost
```c++
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

```

가장 싸게 살 수 있는 가격을 찾는 함수.

# main함수
```c++
int main() {
    int cutNum, brandNum;
    cin >> cutNum >> brandNum;
    
    GuitarString g(cutNum, brandNum);
    cout << g.Cost();
}
```

# 실수했던 점
* 꼭 같은브랜드에서만 살 필요가 없었다. 낱개와 묶음을 같이 살 경우, 낱개로 가장 싼브랜드와 묶음으로 가장 싼 브랜드를 섞어서 사면 가격이 더 낮아질 수 있다.
* 6개 미만일 때는 묶음한개의 가격과 낱개*기타줄 의 가격을 비교해야 한다.
