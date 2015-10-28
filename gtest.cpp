#include <wx/wx.h>
#include <string> 
#include <sstream>
#include <iostream>
#include <map>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <gtest/gtest.h>

using namespace std;

char mbr[512];
TEST(endian , size)
{
	EXPECT_EQ( sizeof(mbr), 512 );
	EXPECT_EQ( sizeof(int), 4 );
	EXPECT_EQ( sizeof(long), 4 );
	EXPECT_EQ( sizeof(long long ), 8 );
}

TEST(fat, info)
{
	EXPECT_EQ((1-1) ,0);
	
}

TEST(wxString, eq)
{
	EXPECT_EQ(wxString(_T("qianqian")), _T("qianqian"));

	
	EXPECT_EQ(string(wxString(_T("qianqian")).mb_str()), 
			 string(wxString(_T("qianqian")).mb_str().data()) );

	// EXPECT_EQ(string(wxString(_T("qianqian")).wc_str()), 
	// 		 	string(wxString(_T("qianqian")).mb_str().data()) );

	//EXPECT_EQ(string(wxString(_T("qianqian")).wc_str()), 
	//		 string(wxString(_T("qianqian")).mb_str().data()) );

}


long testunit(  )
{
	wxString test(_T("   123456    "));
	test.Trim();	  //delete from left
	test.Trim(false); // delete from right 
	printf("|%s|\n", test.mb_str().data());

	return 1;
}

int main(int argc, char *argv[])
{
	testunit();
	testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}

