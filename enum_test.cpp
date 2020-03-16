/*************************************************************************
	> File Name: enum.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月09日 星期四 11时13分14秒
 ************************************************************************/

#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    enum color_set {red,yellow,blue,white,black}; //声明枚举类型color
    color_set color; 
    int i,j,k,counter=0,loop; //counter是累计不同颜色的组合数
    for(i=red;i<=black;i++) {
        for(j=red;j<=black;j++) {
            if(i!=j){                        //前两个球颜色不同
                for(k=red;k<=black;k++)
                if(k!=i&&k!=j){        //第三个球不同于前两个，满足要求
                    counter++;
                    if((counter)%22==0){ //每屏显示22行
                        cout<<"请按回车键继续";
                        cin.get();
                    }
                    cout<<setw(15)<<counter;
                    /*下面输出每种取法，一行为一种取法的三个颜色*/
                    for(loop=1;loop<=3;loop++){
                        switch(loop){
                            case 1: color=(color_set) i; break;    //第一个是i
                            case 2: color=(color_set) j; break;    //第二个是j
                            case 3: color=(color_set) k; break;    //第三个是k
                        }
                        switch(color){
                            case red:   cout<<setw(15)<<"red";   break;
                            case yellow:cout<<setw(15)<<"yellow";break;
                            case blue:  cout<<setw(15)<<"blue";  break;
                            case white:    cout<<setw(15)<<"white"; break;
                            case black: cout<<setw(15)<<"black"; break;
                        }
                    }
                    cout<<endl;            //输出一种取法后换行
                }
            }
        }
    }
    cout<<"共有："<<counter<<"种取法"<<endl;
    return 0;
}


