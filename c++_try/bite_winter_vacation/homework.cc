#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
class Solution
{
    public:
        int lengthOflastWord(string s)
        {
            if(s.size() == 0)
            {
                return 0;
            }
            int m_size = s.size()-1;
            int m_langth = 0;
            while(s[m_size]==' ' && m_size >= 0)
            {
                m_size--; 
            }
            while(s[m_size]!=' ' && m_size >= 0)
            {
                m_size--;
                m_langth++;
            }
            return m_langth;
        }
public:
        void merge(int nums1 ,int m ,int nums2, int n)
        {

        }

};
int main()
{

    return 0;
}

