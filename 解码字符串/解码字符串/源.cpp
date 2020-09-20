class Solution {
public:
	string decodeString(string s) {
		string res = "";
		stack <int> nums;
		stack <string> strs;
		int num = 0;
		int len = s.size();
		for (int i = 0; i < len; ++i)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				num = num * 10 + s[i] - '0';
			}
			else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
			{
				res = res + s[i];
			}
			else if (s[i] == '[') //����[��ǰ������ѹ��numsջ�ڣ� ��ĸ�ַ���ѹ��strsջ��
			{
				nums.push(num);
				num = 0;
				strs.push(res);
				res = "";
			}
			else //������]��ʱ��������֮����ġ�[��֮����ַ���ʹ�÷�����
			{
				int times = nums.top();
				nums.pop();
				for (int j = 0; j < times; ++j)
					strs.top() += res;
				res = strs.top(); //֮����������ĸ���ͻ�ֱ�Ӽӵ�res֮����Ϊ������ͬһ��������
								  //���������ţ�res�ᱻѹ��strsջ����Ϊ��һ�������
				strs.pop();
			}
		}
		return res;
	}
};