#include "JZOff.h"

//ȫ�ǵݹ�˼��
class Solution {
public:
	bool isSubStructure(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool res = false;
		//��Tree1��Tree2����Ϊ���ʱ�򣬲Ž��бȽϡ�����ֱ�ӷ���false
		if (pRoot1 != nullptr && pRoot2 != nullptr) {
			// if(pRoot1 == NULL || pRoot2==NULL) // ����Ҳ�У���ΪԼ��������������һ�������ӽṹ
			   // return false;

			  //����ҵ��˶�ӦTree2�ĸ��ڵ�ĵ㣬�����Ƿ��������
			if (pRoot1->val == pRoot2->val)
				res = DoseTree1HasTree2(pRoot1, pRoot2);
			//�����û�ҵ�������ȥroot��������Ѱ�ң�ȥ�ж�ʱ�����Tree2
			if (!res)
				res = isSubStructure(pRoot1->left, pRoot2);
			//������Ҳ���������ȥroot��������Ѱ�ң�ȥ�ж�ʱ�����Tree2
			if (!res)
				res = isSubStructure(pRoot1->right, pRoot2);
		}
		return res;
	}
	bool  DoseTree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot2 == nullptr)  // �������������if����ò�����ȷ�Ľ������pRoot1 ��pRoot2 ͬʱΪ��ʱ��Ӧ�����ж�proot2
			return true;	// //���Tree2�Ѿ��������˶��ܶ�Ӧ���ϣ�����true

		if (pRoot1 == nullptr)	//���Tree2��û�б����꣬Tree1ȴ�������ˡ�����false
			return false;

		if (pRoot1->val != pRoot2->val)	//���������һ����û�ж�Ӧ�ϣ�����false	
			return false;
		//������ڵ��Ӧ���ϣ���ô�ͷֱ�ȥ�ӽڵ�����ƥ��
		return  DoseTree1HasTree2(pRoot1->left, pRoot2->left) && DoseTree1HasTree2(pRoot1->right, pRoot2->right);
	}
};
