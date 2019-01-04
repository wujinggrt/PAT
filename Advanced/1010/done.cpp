
/*
**@Brief: No.1010 of PAT advanced level.
**@Author:Jason.Lee
**@Date: 2018-7-4
*/

#include<iostream>
#include<cctype>
#include<algorithm>
#include<cmath>

using namespace std;
// Enter a string and convert to a number
long long str2num(string str,int radix){
    long long sum = 0;
    int index = 0;
    int per_digit = 0;
    for(auto t = str.rbegin();t!=str.rend();t++){
        per_digit = isdigit(*t)? *t - '0':*t - 'a' + 10;
        sum+=per_digit*pow(radix,index++);
    }
    return sum;
}

// Enter the known and unknown numbers to find the result radix
long long find_radix(string str,long long num){
    //cout<<"str = "<<str<<endl;
    long long result_radix = -1;
    char it = *max_element(str.begin(),str.end());
    long long low = (isdigit(it)?it - '0':it - 'a' + 10) + 1;
    //cout<<"low = "<<low<<endl;
    long long high = max(low,num);
    while(low<=high){
        long long mid = (low+high)/2;
        long long temp = str2num(str,mid);
        /*
        cout<<"mid = "<<mid<<endl;
        cout<<"temp = "<<temp<<endl;
        cout<<"low = " <<low<<endl;
        cout<<"high = "<<high<<endl;
        */
        if(temp<0||temp>num){
            high = mid - 1;
        }else if(temp<num){
            low = mid + 1;
        }else{
            result_radix = mid;
            break;
        }
    }
    return result_radix;

}

int main(){
    string N1;
    string N2;
    int tag;
    long long radix;
    cin >> N1 >> N2 >> tag >> radix;
    long long known_num = (tag == 1 ? str2num(N1, radix)
                                    : str2num(N2,radix));
    long long result = find_radix((tag == 1 ? N2 : N1), known_num);
    if(result != -1) {
        cout << result << endl;
    } else {
        cout << "Impossible" << endl;
    }
    return 0;
}