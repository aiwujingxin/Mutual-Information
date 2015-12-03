
// ����ϢУ׼����Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ϢУ׼����.h"
#include "����ϢУ׼����Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	

}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C����ϢУ׼����Dlg �Ի���



C����ϢУ׼����Dlg::C����ϢУ׼����Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C����ϢУ׼����Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C����ϢУ׼����Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICTURE, m_TheImage);//�Զ���ؼ���IDC����ؼ���
	DDX_Control(pDX, IDC_VIDEO, m_CamImage);//�Զ���ؼ���IDC����ؼ���
}

BEGIN_MESSAGE_MAP(C����ϢУ׼����Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_OPEN_PICTURE, &C����ϢУ׼����Dlg::OnBnClickedOpenPicture)
	ON_BN_CLICKED(IDC_OPEN_VIDEO, &C����ϢУ׼����Dlg::OnBnClickedOpenVideo)
	ON_BN_CLICKED(IDC_PICTURE_POINT, &C����ϢУ׼����Dlg::OnBnClickedPicturePoint)
	ON_BN_CLICKED(IDC_VIDEO_POINT, &C����ϢУ׼����Dlg::OnBnClickedVideoPoint)
	ON_BN_CLICKED(IDC_ADUJST, &C����ϢУ׼����Dlg::OnBnClickedAdujst)
END_MESSAGE_MAP()


// C����ϢУ׼����Dlg ��Ϣ�������

BOOL C����ϢУ׼����Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	BOOL m_PicturePointdownflag = TRUE; //ȫ��ͼ����ѡȡ���λ��ʼ��ΪFalse
	BOOL m_VideoPointdownflag = FALSE;  //��Ƶ֡ͼ������ѡȡ���λ��ʼ��ΪFalse


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C����ϢУ׼����Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C����ϢУ׼����Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C����ϢУ׼����Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C����ϢУ׼����Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if ((m_PicturePointdownflag == TRUE) && (m_VideoPointdownflag == FALSE))
	{
		//(this->GetDlgItem(IDC_PICTURE))->GetWindowRect(&rect_ctr);
		m_TheImage.GetWindowRect(m_TheImageRect);//��ȡ��ʾȫ��ͼ�����ھ��δ�������
		ScreenToClient(m_TheImageRect);			//ת��Ϊ�Ի����ϵ�����
		point.x -= m_TheImageRect.left;//point��ȡ���������ԶԻ���ͻ������Ͻǵ����꣬��ȥrect_ctr.left��
		point.y -= m_TheImageRect.top;//rect_ctr.top�󣬼�Ϊ������Picture�ؼ����Ͻǵ�����

		if (m_points2.size() <= 3)	
		{ 
			char point_x[4];
			char point_y[4];
			char point_num[4];
			_ltoa(point.x, point_x, 10);
			_ltoa(point.y, point_y, 10);
			_itoa(m_points1.size() + 1, point_num, 10);
			char message[20] = "Point ";
			strcat(message, point_num);
			strcat(message, ": ");
			strcat(message, point_x);
			strcat(message, ",");
			strcat(message, point_y);

			MessageBox(message);
			m_points2.push_back(point);
		}
		else
		{
			MessageBox("��Ŀ�Ѿ�����4����");
			return;
		}
	}
	else if ((m_PicturePointdownflag == TRUE) && (m_VideoPointdownflag == TRUE))
	{
		//(this->GetDlgItem(IDC_VIDEO))->GetWindowRect(&rect_ctr);
		m_CamImage.GetWindowRect(m_CamImageRect);//��ȡ��ʾ��Ƶ֡ͼ�����ھ��δ�
		ScreenToClient(m_CamImageRect);			//ת��Ϊ�Ի����ϵ�����
		point.x -= m_CamImageRect.left;//point��ȡ���������ԶԻ���ͻ������Ͻǵ����꣬��ȥrect_ctr.left��
		point.y -= m_CamImageRect.top;//rect_ctr.top�󣬼�Ϊ������Picture�ؼ����Ͻǵ�����

		if (m_points1.size() <= 3)
		{
			char point_x[4];
			char point_y[4];
			char point_num[4];
			_ltoa(point.x, point_x, 10);
			_ltoa(point.y, point_y, 10);
			_itoa(m_points1.size() + 1, point_num, 10);
			char message[20] = "Point ";
			strcat(message, point_num);
			strcat(message, ": ");
			strcat(message, point_x);
			strcat(message, ",");
			strcat(message, point_y);

			MessageBox(message);
			m_points1.push_back(point);
		}
		else
		{
			MessageBox("��Ŀ�Ѿ�����4����");
			return;
		}
	}

	CDialogEx::OnLButtonUp(nFlags, point);
}


void C����ϢУ׼����Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ


	CDialogEx::OnMouseMove(nFlags, point);
}


void C����ϢУ׼����Dlg::OnBnClickedOpenPicture()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dlg(
		TRUE, _T("*.bmp;*.jpg��*.jpeg"), NULL,
		OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
		_T("image files (*.bmp; *.jpg;*.jpeg) |*.bmp; *.jpg; *.jpeg | All Files (*.*) |*.*||"), NULL
		);                                        // ѡ��ͼƬ��Լ��
	dlg.m_ofn.lpstrTitle = _T("Open Image");    // ���ļ��Ի���ı�����
	if (dlg.DoModal() != IDOK)                    // �ж��Ƿ���ͼƬ
		return;

	CString mPath = dlg.GetPathName();            // ��ȡͼƬ·��

	TheImage = cvLoadImage(mPath, 1);    // ��ȡͼƬ�����浽һ���ֲ����� ipl ��
	//Mat TheImage = imread(mPath,1);
	ShowMatImgToWnd(GetDlgItem(IDC_PICTURE), TheImage);
	//DrawPicToHDC(TheImage, IDC_PICTURE);            // ������ʾͼƬ����    
	UpdateWindow();

}


void C����ϢУ׼����Dlg::OnBnClickedOpenVideo()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dlg(
		TRUE, _T("*.bmp;*.jpg��*.jpeg"), NULL,
		OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
		_T("image files (*.bmp; *.jpg;*.jpeg) |*.bmp; *.jpg; *.jpeg | All Files (*.*) |*.*||"), NULL
		);                                        // ѡ��ͼƬ��Լ��
	dlg.m_ofn.lpstrTitle = _T("Open Image");    // ���ļ��Ի���ı�����
	if (dlg.DoModal() != IDOK)                    // �ж��Ƿ���ͼƬ
		return;

	CString mPath = dlg.GetPathName();            // ��ȡͼƬ·��

	CamImage = cvLoadImage(mPath, 1);    // ��ȡͼƬ�����浽һ���ֲ����� ipl ��
	//Mat TheImage = imread(mPath,1);
	ShowMatImgToWnd(GetDlgItem(IDC_VIDEO), CamImage);
	//DrawPicToHDC(TheImage, IDC_PICTURE);            // ������ʾͼƬ����    
	UpdateWindow();


}


void C����ϢУ׼����Dlg::OnBnClickedPicturePoint()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_PicturePointdownflag = TRUE;
	m_VideoPointdownflag = FALSE;
}


void C����ϢУ׼����Dlg::OnBnClickedVideoPoint()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	m_VideoPointdownflag = TRUE;
}


void C����ϢУ׼����Dlg::OnBnClickedAdujst()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	vector<CPoint> Newpoints;// = m_points2; // ��Ҫ���û���Ϣ�Ӻ������µõ���ƥ��㼯��Ҫ���ĸ��� 
	vector<CPoint> Points1 = m_points1;// ��Ƶ֡ͼ��ƥ��㼯��Ҫ���ĸ���
	vector<CPoint> Points2 = m_points2;// ȫ��ͼ��ƥ��㼯����ʼƥ��㼯��Ҫ���ĸ���

	Newpoints = Refresh_MacthPoints(Points1, Points2);//����ȫ��ͼ���ĸ���ȷƥ��㼯

	m_newpoints = Newpoints;
}


// ��ͼ����ʾ����Ӧ��ͼ���
void C����ϢУ׼����Dlg::ShowMatImgToWnd(CWnd* pWnd, cv::Mat img)
{
	if (img.empty())
		return;
	CDC *pDC = pWnd->GetDC();
	HDC hDC = pDC->GetSafeHdc();
	CRect rect;
	pWnd->GetClientRect(&rect);
	IplImage Iimg = img;
	CvvImage cimg;
	cimg.CopyOf(&Iimg); // ����ͼƬ
	cimg.DrawToHDC(hDC, &rect); // ��ͼƬ���Ƶ���ʾ�ؼ���ָ��������
	ReleaseDC(pDC);
}


//����ͼ����Ϣ�ؼ���
double C����ϢУ׼����Dlg::Entropy(Mat img)
{
	double temp[256] = {0.0};


	// ����ÿ�����ص��ۻ�ֵ
	for (int m = 0; m<img.rows; m++)
	{// ��Ч�������еķ�ʽ
		const uchar* t = img.ptr<uchar>(m);
		for (int n = 0; n<img.cols; n++)
		{
			int i = t[n];
			temp[i] = temp[i] + 1;
		}
	}

	// ����ÿ�����صĸ���
	for (int i = 0; i<256; i++)
	{
		temp[i] = temp[i] / (img.rows*img.cols);
	}

	double result = 0;
	// ����ͼ����Ϣ��
	for (int i = 0; i<256; i++)
	{
		if (temp[i] == 0.0)
			result = result;
		else
			result = result - temp[i] * (log(temp[i]) / log(2.0));
	}

	return result;

}




// ����ͼ��������Ϣ�ؼ���
double C����ϢУ׼����Dlg::ComEntropy(Mat img1, Mat img2, double img1_entropy, double img2_entropy)
{
	double temp[256][256] = {0.0};


	// ��������ͼ�����ص��ۻ�ֵ
	for (int m1 = 0, m2 = 0; m1 < img1.rows, m2 < img2.rows; m1++, m2++)
	{    // ��Ч�������еķ�ʽ
		const uchar* t1 = img1.ptr<uchar>(m1);
		const uchar* t2 = img2.ptr<uchar>(m2);
		for (int n1 = 0, n2 = 0; n1 < img1.cols, n2 < img2.cols; n1++, n2++)
		{
			int i = t1[n1], j = t2[n2];
			temp[i][j] = temp[i][j] + 1;
		}
	}

	// ����ÿ���������صĸ���
	for (int i = 0; i < 256; i++)
	{
		for (int j = 0; j < 256; j++)

		{
			temp[i][j] = temp[i][j] / (img1.rows*img1.cols);
		}
	}

	double result = 0.0;
	//����ͼ��������Ϣ��
	for (int i = 0; i < 256; i++)
	{
		for (int j = 0; j < 256; j++)

		{
			if (temp[i][j] == 0.0)
				result = result;
			else
				result = result - temp[i][j] * (log(temp[i][j]) / log(2.0));
		}
	}

	//�õ�����ͼ��Ļ���Ϣ��
	img1_entropy = Entropy(img1);
	img2_entropy = Entropy(img2);
	result = img1_entropy + img2_entropy - result;

	return result;

}





//����ȫ��ͼ���ĸ���ȷƥ��㼯
vector<CPoint> C����ϢУ׼����Dlg::Refresh_MacthPoints(vector<CPoint> points1, vector<CPoint> points2)
{
	int IMGSIDE = 15; //��ȡ��������ͼ�ı߳�һ��
	int IMAGESIDE = 15; //�ֲ���������İ뾶

	points1 = m_points1; // ��Ƶ֡ͼ��ƥ��㼯
	points2 = m_points2; // ȫ��ͼ��ƥ��㼯����ʼƥ��㣬��Ҫ���û���Ϣ�Ӻ�������

	//// Mat TheImage; //ȫ��ͼ
	//// Mat CamImage; //��Ƶ֡ͼ��

	Mat dst1[4];   // ��Ƶ֡ͼ���Ͻ�ȡ���ĸ������ͼ
	Mat dst2[4];   // ȫ��ͼ���Ͻ�ȡ���ĸ������ͼ




	cv::Point CLSPoint[4], CRXPoint[4];
	//��ȡ��Ƶ֡ͼ����ͼ
	for (int i = 0; i<4; i++)
	{
		CLSPoint[i].x = points1.at(i).x - IMGSIDE;
		CLSPoint[i].y = points1.at(i).y - IMGSIDE;
		CRXPoint[i].x = points1.at(i).x + IMGSIDE;
		CRXPoint[i].y = points1.at(i).y + IMGSIDE;	
	}

	Rect ROI0(CLSPoint[0], CRXPoint[0]);
	Rect ROI1(CLSPoint[1], CRXPoint[1]);
	Rect ROI2(CLSPoint[2], CRXPoint[2]);
	Rect ROI3(CLSPoint[3], CRXPoint[3]);
	CamImage(ROI0).copyTo(dst1[0]);
	CamImage(ROI1).copyTo(dst1[1]);
	CamImage(ROI2).copyTo(dst1[2]);
	CamImage(ROI3).copyTo(dst1[3]);



	cv::Point TLSPoint[4], TRXPoint[4];
	//��ȡȫ��ͼͼ����ͼ
	for (int i = 0; i<4; i++)
	{

		TLSPoint[i].x = points2.at(i).x - IMGSIDE;
		TLSPoint[i].y = points2.at(i).y - IMGSIDE;
		TRXPoint[i].x = points2.at(i).x + IMGSIDE;
		TRXPoint[i].y = points2.at(i).y + IMGSIDE;

	}

	Rect ROI00(TLSPoint[0], TRXPoint[0]);
	Rect ROI11(TLSPoint[1], TRXPoint[1]);
	Rect ROI22(TLSPoint[2], TRXPoint[2]);
	Rect ROI33(TLSPoint[3], TRXPoint[3]);
	TheImage(ROI00).copyTo(dst2[0]);
	TheImage(ROI11).copyTo(dst2[1]);
	TheImage(ROI22).copyTo(dst2[2]);
	TheImage(ROI33).copyTo(dst2[3]);


	//�����Ӧͼ���ӿ�Ļ���Ϣ��
	double OneImaEntropy1[4]; //��Ƶ֡ͼ����Ϣ��
	double OneImaEntropy2[4]; //ȫ��ͼ��Ϣ��
	double TwoImaEntropy[4]; //��ʼ����Ϣ��

	for (int i = 0; i<4; i++)
	{
		OneImaEntropy1[i] = Entropy(dst1[i]);
		OneImaEntropy2[i] = Entropy(dst2[i]);
		TwoImaEntropy[i] = ComEntropy(dst1[i], dst2[i], OneImaEntropy1[i], OneImaEntropy2[i]);
	}

	vector<CPoint> NewPoints; // ���µ��ĸ�ƥ��㼯

	 Rect rect[4][30][30];
	 Mat dst[4][30][30];

	double OneImaEntropy[4][30][30];
	double NewTwoEntropy[4][30][30];

	//ȫ��ͼ��ƥ��㼯�ľֲ�������������ȷƥ��㼯
	for (int i = 0; i < 4; i++)
	{
		for (int j = points2.at(i).x - IMAGESIDE; j <= points2.at(i).x + IMAGESIDE; j++)
		{
			for (int k = points2.at(i).y - IMAGESIDE; k <= points2.at(i).y + IMAGESIDE; k++)
			{
				rect[i][j][k] = Rect(j - IMGSIDE, k - IMGSIDE, 2 * IMGSIDE, 2 * IMGSIDE); //j��kΪ���µľֲ�����ͼ������						  
				TheImage(rect[i][j][k]).copyTo(dst[i][j][k]);

				OneImaEntropy[i][j][k] = Entropy(dst[i][j][k]);
				NewTwoEntropy[i][j][k] = ComEntropy(dst[i][j][k], dst1[i], OneImaEntropy[i][j][k], OneImaEntropy1[i]);

				double MAX = TwoImaEntropy[i];
				//���滥��Ϣ�����ʱ��ƥ��㼯 
				if (NewTwoEntropy[i][j][k] > MAX)   // �������л���Ϣ�أ�Ȼ��ȡ���ֵ
				{
					MAX = NewTwoEntropy[i][j][k];
					NewPoints.at(i).x = j;
					NewPoints.at(i).y = k;
				}
			}
		}
	}

	return  NewPoints;

}

