#include <string>
#include <iostream>
using namespace std;

const char *chnNumChar[10] = { "零", "一", "二", "三", "四", "五", "六", "七", "八", "九" };
const char *chnUnitChar[] = { "", "十", "百", "千" };
//以万为节 划分的节权位 
const char *chnUnitSection[] = { "", "万", "亿", "万亿" };

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
		/*是否需要节权位？*/
		strIns += (section != 0) ? chnUnitSection[unitPos] : chnUnitSection[0];
		chnStr.insert(0, strIns);
		/*若千位是0 则在下一个section时补零*/
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
