#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
    int buff;
    ifstream text("Packages.txt");
    vector <int> num;
    vector <int> num2;
    int max = -1,min = 33000;

    while(!text.eof())
    {
        text >> buff;
        cout << buff << endl;
        num.insert(num.end(),buff);

        for(int k=0;k<num.size();++k)
        {
            if(max<num[k])
                max = num[k];
            if(min>num[k])
                min = num[k];
        }

        for(int r=min;r<=max;++r)
            num2.insert(num2.end(),r);

        for(int y=0; y<num2.size();++y)
        {
            for(int g=0;g<num.size();++g)
            {
                if(num2[y]==num[g])
                {
                    num2.erase(num2.begin()+y);
                    --y;
                }

            }
        }

        if(num2.empty())
            cout << "Message "<< min << "-" << max << " get correctly" << endl;
        else
        {
            cout << "Message "<< min << "-" << max << " get uncorrectly, need: ";
            for(int i=0; i<num2.size();++i)
                cout << num2[i] << " ";
            cout << endl;
        }
        num2.clear();
    }

    text.close();
    return 0;
}
