#include"UIlib.h"
using namespace DuiLib;

#pragma comment(lib,"DuiLib_ud.lib")

#include<fstream>

class DuiWinWnd : public WindowImplBase
{
protected:
	virtual CDuiString GetSkinFolder()
	{
		return _T("");
	}
	virtual CDuiString GetSkinFile()
	{
		return _T("gifMake.xml");
	}
	virtual LPCTSTR GetWindowClassName(void) const
	{
		return _T("GIFMakeWnd");
	}
	virtual void Notify(TNotifyUI& msg)
	{
		CDuiString strName = msg.pSender->GetName();
		if (msg.sType == _T("click"))
		{
			if (strName == _T("close"))
			{
				Close();
			}
			else if (strName == _T("small"))
			{
				MessageBox(NULL, _T("text"), _T("����"), IDOK);
			}
			else if (strName == _T("Button1"))
			{
				LoadFile();
			}
			else if (strName == _T("����2"))
			{
				GenerateGifWithPic();
			}
			else if (strName == _T("��ȡ"))
			{
				CutView();
			}
			else if (strName == _T("��ȡ1"))
			{
				GetSRTFile();
				LoadSRT();
			}
			else if (strName == _T("Button4"))
			{
				CListUI *pEdit = (CListUI*)m_PaintManager.FindControl(_T("edit_word"));
				CDuiString strWord = pEdit->GetText();
				CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("List1"));
				CListTextElementUI* pListItemp = (CListTextElementUI*)pList->GetItemAt(pList->GetCurSel());
				pListItemp->SetText(1, strWord);
			}
			else if (strName == _T("д��"))
			{
				WriteSRT();
			}
			else if (strName == _T("��ȡ2"))
			{
				GenerateView();
			}
			else if (strName == _T("��¼"))
			{
				BornSRT2View();
			}
			else if (strName == _T("����1"))
			{
				GenerateGifWithView();
			}
		}
		else if (msg.sType == _T("itemselect"))
		{
			if (strName == _T("List1"))
			{
				//��ȡlist�Ŀռ�
				CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("List1"));
				//��ȡ��ǰlist��ѡ�е�һ��
				CListTextElementUI* pListItemp = (CListTextElementUI*)pList->GetItemAt(pList->GetCurSel());
				//��list����ѡ��������ӵ�edit��
				CListUI *pEdit = (CListUI*)m_PaintManager.FindControl(_T("edit_word"));
				pEdit->SetText(pListItemp->GetText(1));
			}
			if (strName == _T("Combo1"))
			{
				//ѡ��ͼƬ��ʽ����
				CComboBoxUI* pComboUI = (CComboBoxUI*)m_PaintManager.FindControl(_T("Combo1"));
				if (0 == pComboUI->GetCurSel())
				{
					((CEditUI*)m_PaintManager.FindControl(_T("edit_start")))->SetEnabled(false);
					((CEditUI*)m_PaintManager.FindControl(_T("edit_end")))->SetEnabled(false);
					((CEditUI*)m_PaintManager.FindControl(_T("��ȡ1")))->SetEnabled(false);
					((CEditUI*)m_PaintManager.FindControl(_T("д��")))->SetEnabled(false);
					((CEditUI*)m_PaintManager.FindControl(_T("��ȡ2")))->SetEnabled(false);
					((CEditUI*)m_PaintManager.FindControl(_T("��¼")))->SetEnabled(false);
					((CEditUI*)m_PaintManager.FindControl(_T("Button2")))->SetEnabled(false);
					((CEditUI*)m_PaintManager.FindControl(_T("Button3")))->SetEnabled(false);
					((CEditUI*)m_PaintManager.FindControl(_T("��ȡ")))->SetEnabled(false);
					((CEditUI*)m_PaintManager.FindControl(_T("edit_word")))->SetEnabled(false);
					((CEditUI*)m_PaintManager.FindControl(_T("Button4")))->SetEnabled(false);
					((CEditUI*)m_PaintManager.FindControl(_T("����1")))->SetEnabled(false);
					((CEditUI*)m_PaintManager.FindControl(_T("����2")))->SetEnabled(true);
				}
				else
				{
					((CEditUI*)m_PaintManager.FindControl(_T("edit_start")))->SetEnabled(true);
					((CEditUI*)m_PaintManager.FindControl(_T("edit_end")))->SetEnabled(true);
					((CEditUI*)m_PaintManager.FindControl(_T("��ȡ1")))->SetEnabled(true);
					((CEditUI*)m_PaintManager.FindControl(_T("д��")))->SetEnabled(true);
					((CEditUI*)m_PaintManager.FindControl(_T("��ȡ2")))->SetEnabled(true);
					((CEditUI*)m_PaintManager.FindControl(_T("��¼")))->SetEnabled(true);
					((CEditUI*)m_PaintManager.FindControl(_T("Button2")))->SetEnabled(true);
					((CEditUI*)m_PaintManager.FindControl(_T("Button3")))->SetEnabled(true);
					((CEditUI*)m_PaintManager.FindControl(_T("��ȡ")))->SetEnabled(true);
					((CEditUI*)m_PaintManager.FindControl(_T("edit_word")))->SetEnabled(true);
					((CEditUI*)m_PaintManager.FindControl(_T("Button4")))->SetEnabled(true);
					((CEditUI*)m_PaintManager.FindControl(_T("����1")))->SetEnabled(true);
					((CEditUI*)m_PaintManager.FindControl(_T("����2")))->SetEnabled(false);
				}
			}
		}
	}

	void SendMessage(CDuiString strCMD)
	{
		SHELLEXECUTEINFO strSEInfo;
		memset(&strSEInfo, 0, sizeof(SHELLEXECUTEINFO));
		strSEInfo.cbSize = sizeof(SHELLEXECUTEINFO);
		strSEInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
		strSEInfo.lpFile = _T("C:\\Windows\\System32\\cmd.exe");
		strSEInfo.lpParameters = strCMD;
		strSEInfo.nShow = SW_HIDE;

		ShellExecuteEx(&strSEInfo);

		WaitForSingleObject(strSEInfo.hProcess, INFINITE);

		MessageBox(NULL, _T("text"), _T("����"), IDOK);
	}

	void GenerateGifWithPic()
	{
		//ffmpeg -r 3 -i .\Pictrue\%d.jpg output.gif -y
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		//��������
		strPath += _T("ffmpeg\\");
		CDuiString strCMD;
		strCMD += _T("/c ");
		strCMD += strPath;
		strCMD += _T("ffmpeg -r 3 -i ");
		strCMD += strPath;
		strCMD += _T("Pictrue\\%d.jpg ");
		strCMD += strPath;
		strCMD += _T("output.gif -y");
		//������
		SendMessage(strCMD);
	}

	void CutView()
	{
		//��������
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpeg\\");

		CDuiString strViewPath = ((CEditUI*)m_PaintManager.FindControl(_T("Edit1")))->GetText();

		CDuiString strCMD;
		strCMD += _T("/c ");
		strCMD += strPath;
		strCMD += _T("ffmpeg -i ");
		if (!strViewPath.IsEmpty())
		{
			strCMD += strViewPath;
		}
		else
		{
			strCMD += strPath;
			strCMD += _T("input.mkv");
		}
		strCMD += _T(" -vcodec copy -acodec copy -ss ");
		strCMD += _T(" ");
		//��ȡ��ʼʱ��ͽ�βʱ��
		CDuiString strStartTime = ((CEditUI*)m_PaintManager.FindControl(_T("edit_start")))->GetText();
		if (!(IsTimeTrue(strStartTime)))
		{
			MessageBox(NULL, _T("��ʼʱ�����"), _T("����"), IDOK);
			return;
		}
		CDuiString strEndTime = ((CEditUI*)m_PaintManager.FindControl(_T("edit_end")))->GetText();
		if (!(IsTimeTrue(strEndTime)))
		{
			MessageBox(NULL, _T("����ʱ�����"), _T("����"), IDOK);
		}
		strCMD += strStartTime;
		strCMD += _T(" -to ");
		strCMD += strEndTime;
		strCMD += _T(" ");
		strCMD += strPath;
		strCMD += _T("11.mkv -y");

		SendMessage(strCMD);
	}

	void GetSRTFile()
	{
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpeg\\");
		CDuiString strCMD;
		strCMD += _T("/c ");
		strCMD += strPath;
		strCMD += _T("ffmpeg -i ");
		strCMD += strPath;
		strCMD += _T("11.mkv ");
		strCMD += strPath;
		strCMD += _T("11.srt -y");

		SendMessage(strCMD);
	}

	void LoadFile()
	{
		OPENFILENAME ofn;
		memset(&ofn, 0, sizeof(OPENFILENAME));
		TCHAR strPath[MAX_PATH] = { 0 };
		ofn.lStructSize = sizeof(OPENFILENAME);
		ofn.lpstrFile = strPath;
		ofn.nMaxFile = sizeof(strPath);
		ofn.lpstrFilter = _T("All(*.*)\0*.*\0Text(*.txt)\0*.TXT\0\0");
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (GetOpenFileName(&ofn))
		{
			((CEditUI*)m_PaintManager.FindControl(_T("Edit1")))->SetText(strPath);
		}
	}

	void LoadSRT()
	{
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpeg\\11.srt");
		std::ifstream fIn(strPath.GetData());

		char strSRTCon[512] = { 0 };
		CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("List1"));
		pList->RemoveAll();
		while (!fIn.eof())
		{
			//��ȡ���
			fIn.getline(strSRTCon, 512);

			CListTextElementUI* pListItem = new CListTextElementUI;
			pList->Add(pListItem);
			//��ȡʱ����
			fIn.getline(strSRTCon, 512);
			pListItem->SetText(0, UTF8ToUnicode(strSRTCon));
			//��ȡ��Ļ
			fIn.getline(strSRTCon, 512);
			pListItem->SetText(1, UTF8ToUnicode(strSRTCon));
			//��ȡ����
			fIn.getline(strSRTCon, 512);
		}

		fIn.close();
	}

	void WriteSRT()
	{
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpeg\\11.srt");
		std::ofstream fOut(strPath.GetData());

		CListUI* pList = (CListUI*)m_PaintManager.FindControl(_T("List1"));
		int szCount = pList->GetCount();
		for (int i = 0; i < szCount; ++i)
		{
			CListTextElementUI* pListItem = (CListTextElementUI*)pList->GetItemAt(i);
			//���
			CDuiString strNo;
			strNo.Format(_T("%d"), i + 1);
			//ʱ����
			CDuiString strTime = pListItem->GetText(0);
			//����
			CDuiString strWord = pListItem->GetText(1);
			//д��
			//д�к�
			string strNewLine = Unicode2ANSI(_T("\n"));
			string itemNo = Unicode2ANSI(strNo);
			fOut.write(itemNo.c_str(), itemNo.size());
			fOut.write(strNewLine.c_str(), strNewLine.size());
			//дʱ����
			string itemTime = Unicode2ANSI(strTime);
			fOut.write(itemTime.c_str(), itemTime.size());
			fOut.write(strNewLine.c_str(), strNewLine.size());
			//д�ı�
			string itemWord = Unicode2ANSI(strWord);
			fOut.write(itemWord.c_str(), itemWord.size());
			fOut.write(strNewLine.c_str(), strNewLine.size());
			//д����
			fOut.write(strNewLine.c_str(), strNewLine.size());
		}
		fOut.close();
	}

	void GenerateView()
	{
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpeg\\");
		CDuiString strCMD;
		strCMD += _T("/c ");
		strCMD += strPath;
		strCMD += _T("ffmpeg -i ");
		strCMD += strPath;
		strCMD += _T("11.mkv -vcodec copy -an -sn ");
		strCMD += strPath;
		strCMD += _T("22.mkv -y");
		SendMessage(strCMD);
	}

	void BornSRT2View()
	{
		CDuiString strCMD1;
		strCMD1 += _T("/c cd ");
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpeg ");
		strCMD1 += strPath;
		CDuiString strCMD2;
		strCMD2 += _T("& ffmpeg -i 22.mkv -vf subtitles=11.srt 33.mkv -y");
		strCMD1 += strCMD2;
		SendMessage(strCMD1);
	}

	void GenerateGifWithView()
	{
		CDuiString strPath = CPaintManagerUI::GetInstancePath();
		strPath += _T("ffmpeg\\");
		CDuiString strCMD;
		strCMD += _T("/c ");
		strCMD += strPath;
		strCMD += _T("ffmpeg -i ");
		strCMD += strPath;
		strCMD += _T("33.mkv -vf scale=iw/2:ih/2 -f gif ");
		strCMD += strPath;
		strCMD += _T("output.gif -y");
		SendMessage(strCMD);
	}

	CDuiString UTF8ToUnicode(const char* str)
	{
		int szLen = ::MultiByteToWideChar(CP_UTF8, 0, str, strlen(str), NULL, 0);
		wchar_t* pContent = new wchar_t[szLen + 1];
		::MultiByteToWideChar(CP_UTF8, 0, str, strlen(str), pContent, szLen);
		pContent[szLen] = '\0';
		CDuiString s(pContent);
		delete[] pContent;
		return s;
	}
	string Unicode2ANSI(CDuiString str)
	{
		int szLen = ::WideCharToMultiByte(CP_ACP, 0, str.GetData(), -1, NULL, 0, NULL, FALSE);
		char* pBuff = new char[szLen + 1];
		::WideCharToMultiByte(CP_ACP, 0, str.GetData(), -1, pBuff, szLen, NULL, FALSE);
		pBuff[szLen] = '\0';
		string s(pBuff);
		delete[] pBuff;
		return s;
	}

	bool IsTimeTrue(CDuiString strTime)
	{
		//00:00:00
		if (strTime.GetLength() != 8)
		{
			return false;
		}
		for (int i = 0; i < strTime.GetLength(); i++)
		{
			if (strTime[i] == ':')
				continue;
			if (!(strTime[i] >= '0' && strTime[i] <= '9'))
				return false;
		}
		return true;
	}
};

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());
	DuiWinWnd wnd;

	wnd.Create(NULL, _T("MakeGif"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	wnd.CenterWindow();
	wnd.ShowModal();
	return 0;
}
