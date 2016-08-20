#include <string>
#include <iostream>
using namespace std;

const char *chnNumChar[10] = { "��", "һ", "��", "��", "��", "��", "��", "��", "��", "��" };
const char *chnUnitChar[] = { "", "ʮ", "��", "ǧ" };
//����Ϊ�� ���ֵĽ�Ȩλ 
const char *chnUnitSection[] = { "", "��", "��", "����" };

void SectionToChinese(unsigned int section, string& chnStr) {
	chnStr.clear();
	string strIns;
	int unitPos = 0;
	bool zero = true;
	while(section > 0) {
		int v = section % 10;
		if(v == 0) {
			if( (section == 0) || !zero ) {
				zero = true; 
				chnStr.insert(0, chnNumChar[v]);
			}
		} else {
			zero = false; 
			strIns = chnNumChar[v]; 
			strIns += chnUnitChar[unitPos]; 
			chnStr.insert(0, strIns);
		}
		
		section /= 10;
		++unitPos; 
		
	}
}

void NumberToChinese(unsigned int num, string& chnStr) {
	chnStr.clear();
	int unitPos = 0;
	string strIns;
	bool needZero = false;

	if(num == 0) {
		chnStr = chnNumChar[0];
		return;
	}

	while(num > 0) {
		unsigned int section = num % 10000;
		if(needZero) {
			chnStr.insert(0, chnNumChar[0]);
		}
		SectionToChinese(section, strIns);
		/*�Ƿ���Ҫ��Ȩλ��*/
		strIns += (section != 0) ? chnUnitSection[unitPos] : chnUnitSection[0];
		chnStr.insert(0, strIns);
		/*��ǧλ��0 ������һ��sectionʱ����*/
		needZero = (section < 1000) && (section > 0);
		
		num /= 10000;
		++unitPos;
	}
}

int main() {

	string strch;
	
	NumberToChinese(20012345,strch);
	
	cout<<strch<<endl;
	
	return 0;
}
