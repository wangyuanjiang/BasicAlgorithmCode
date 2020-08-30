#include "JZOff.h"


//�Լ�д�ģ� �Ӹ���㿪ʼѰ��p,q �����p,qͬʱ��root��������������root������������Ѱ�ң����p��qͬʱ��root����������
//����root������������Ѱ�ң����򷵻�root��
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL ||root ==p || root == q)
			return root;
		while (root) {
			if (findTree(root->left, p) && findTree(root->left, q))
				root = root->left;

			else if (findTree(root->right, p) && findTree(root->right, q))
				root = root->right;
			else
				break;
		}

		return root;

	}

	bool findTree(TreeNode* root, TreeNode* p) {


		if (root == NULL)    return false;	//root Ϊ��˵��û�ҵ�

		bool res = false;	

		if (root->val == p->val)		//ֵ��ȣ�˵���ҵ���
			res = true;

		if (!res)
			res = findTree(root->left, p);	//�������ݹ�find
		if (!res)
			res = findTree(root->right, p);	//�������ݹ�find

		return res;
	}
};

/*��ΪlowestCommonAncestor(root, p, q)�Ĺ������ҳ���rootΪ���ڵ�������ڵ�p��q������������ȣ�
���Եݹ��������������ۣ�

���p��q�ֱ���root�����ҽڵ㣬��ôroot��������Ҫ�ҵ������������
���p��q����root����ڵ㣬��ô����lowestCommonAncestor(root->left,p,q)
���p��q����root���ҽڵ㣬��ô����lowestCommonAncestor(root->right,p,q)

�߽��������ۣ�!!!!!!!!!!!!!!!!!
���root��null����˵�������Ѿ��ҵ�����ˣ�����null��ʾû�ҵ�
���root��p��Ȼ�����q��ȣ��򷵻�root
���������û�ҵ����ݹ麯������null��֤��p��qͬ��root���Ҳ࣬��ô���յĹ������Ⱦ����������ҵ��Ľ��
���������û�ҵ����ݹ麯������null��֤��p��qͬ��root����࣬��ô���յĹ������Ⱦ����������ҵ��Ľ��*/

class Solution {	//���˵ĵݹ�

public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		// ��root����p ����p
		// ��root����q ����q
		// ��root�������� ����NULL
		// ����root�������а���p��q ����root(�����������)
		if (!root || root == p || root == q) return root;

		auto left =  lowestCommonAncestor(root->left, p, q);
		auto right = lowestCommonAncestor(root->right, p, q);

		if (!left) return right;
		if (!right) return left;

		return root;
	}
};

