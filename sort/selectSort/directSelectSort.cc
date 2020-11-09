#include<iostream>
#include<vector>

using namespace std;
class Sort{
  public:
    static void swap(int *i,int *j)
    {
      int k = *i;
      *i = *j;
      *j = k;

    }
    static void shellSort(vector<int> &src)
    {
      int gap = src.size() / 2;

      while (gap)
      {
        for (int i = 0;i + gap < src.size();i++)
        {
          if (src[i] > src[i + gap])
            swap(&src[i], &src[i + gap]);

        }
        gap /= 2;

      }

    }
    static void selectSort(vector<int> &src)
    {
      for (int i = 0; i < src.size(); i++)
      {
        int tmp = i;
        for (int j = i; j < src.size(); j++)
        {
          if (src[tmp] > src[j])
            tmp = j;

        }
        swap(&src[tmp], &src[i]);

      }

    }

};
int main()
{
  vector<int> arr = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5  };
  Sort::shellSort(arr);
  Sort::selectSort(arr);

  for (auto e : arr)
  {
    cout << e << " ";
  }
  cout << endl;

  return 0;
}

