#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

std::string findSum(std::string, std::string);

int main()
{
    std::ifstream inFile;
    std::ofstream myfile;
    std::string A,B;

    inFile.open("input.txt");
    inFile >>A>>B;
    inFile.close();

    if ((A.size() > 10000)  || (B.size() > 10000) ) {
    }else{
        myfile.open ("output.txt");
        myfile << findSum(A, B);;
        myfile.close();
    }

    return 0;
}

std::string findSum(std::string str1, std::string str2){
    if (str1.length() > str2.length())
        swap(str1, str2);

    std::string str = ""; //result

    int n1 = str1.length(), n2 = str2.length();
    int diff = n2 - n1;

    // Initially take carry zero
    int carry = 0;

    // Traverse from end of both strings
    for (int i=n1-1; i>=0; i--)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0') +
                   (str2[i+diff]-'0') +
                   carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    // Add remaining digits of str2[]
    for (int i=n2-n1-1; i>=0; i--)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');

    // reverse resultant string
    std::reverse(str.begin(), str.end());

    return str;
}
