#include<iostream>
#include<stack>
#include<vector>

using namespace std;
class TreeNode {
public:
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode(int _val):val(_val),left(NULL),right(NULL)
  {}
};

class solution{
public:
  static vector<int> post(TreeNode *root)
  {
    vector<int> ret;
    TreeNode *head = root;
    stack<TreeNode *> st;
    stack<bool> flag;

    st.push(head);
    flag.push(false);

    while(true)
    {
      if(head->left)
      {
        st.push(head->left);
        flag.push(false);
        head = head->left;
      }
      else if(st.size())
      {
        while(flag.top())
        {
          ret.push_back(st.top()->val);
          st.pop();
          flag.pop();
        }
        head = st.top();
        flag.pop();
        flag.push(true);
        if(head->right)
        {
          head = head->right;
          st.push(head);
          flag.push(false);
        }
      }
      else 
      {
        break;
      }
    }

    return ret;
  }


};
int main()
{
  TreeNode *l1 = new TreeNode(1);
  TreeNode *l2 = new TreeNode(1);
  TreeNode *l3 = new TreeNode(1);
  l1->right = l2;
  l2->left = l3;
  
  vector<int> ret = solution::post(l1);

  for(size_t i = 0;i < ret.size();i++)
  {
    cout << ret[i] << endl;
  }

  return 0;
}
