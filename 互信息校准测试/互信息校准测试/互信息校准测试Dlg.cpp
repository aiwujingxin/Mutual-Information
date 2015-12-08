
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

	BOOL m_PicturePointdownflag = FALSE; //ȫ��ͼ����ѡȡ���λ��ʼ��ΪFalse
	BOOL m_VideoPointdownflag = FALSE;  //��Ƶ֡ͼ������ѡȡ���λ��ʼ��ΪFalse

	GetDlgItem(IDC_PICTURE_POINT)->EnableWindow(FALSE); //��ʼ״̬,��ȡ�����㰴ť��ʧ�ܵ�
	GetDlgItem(IDC_VIDEO_POINT)->EnableWindow(FALSE); //��ʼ״̬,��ȡ�����㰴ť��ʧ�ܵ�
	GetDlgItem(IDC_ADUJST)->EnableWindow(FALSE); //��ʼ״̬,���㻥��Ϣ��ť��ʧ�ܵ�
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
	    (this->GetDlgItem(IDC_PICTURE))->GetWindowRect(&m_TheImageRect);
		m_TheImage.GetWindowRect(m_TheImageRect);//��ȡ��ʾȫ��ͼ�����ھ��δ�������
		ScreenToClient(m_TheImageRect);			//ת��Ϊ�Ի����ϵ�����
		point.x -= m_TheImageRect.left;//point��ȡ���������ԶԻ���ͻ������Ͻǵ����꣬��ȥrect_ctr.left��
		point.y -= m_TheImageRect.top;//rect_ctr.top�󣬼�Ϊ������Picture�ؼ����Ͻǵ�����

		if (m_points2.size() <= 3)	
		{ 
			if (point.x < 0 || point.x > m_TheImageRect.Width() || point.y < 0 || point.y > m_TheImageRect.Height())
			{
				MessageBox("ѡȡ�ĵ㲻��Ŀ��ͼ��Χ�ڣ�");
			}
			else
			{
				char point_x[5];
				char point_y[5];
				char point_num[4];
				_ltoa(point.x, point_x, 10);
				_ltoa(point.y, point_y, 10);
				_itoa(m_points2.size() + 1, point_num, 10);
				char message[20] = "Point ";
				strcat(message, point_num);
				strcat(message, ": ");
				strcat(message, point_x);
				strcat(message, ",");
				strcat(message, point_y);

				MessageBox(message);
				m_points2.push_back(point);
			}
		}
		
		if (m_points2.size() >= 4)
		{
			MessageBox("��ͼ��ѡȡ����������Ŀ�Ѿ��ﵽ4��");
			return;
		}
	}
	else if ((m_PicturePointdownflag == TRUE) && (m_VideoPointdownflag == TRUE))
	{
		(this->GetDlgItem(IDC_VIDEO))->GetWindowRect(&m_CamImageRect);
		m_CamImage.GetWindowRect(m_CamImageRect);//��ȡ��ʾ��Ƶ֡ͼ�����ھ��δ�
		ScreenToClient(m_CamImageRect);			//ת��Ϊ�Ի����ϵ�����
		point.x -= m_CamImageRect.left;//point��ȡ���������ԶԻ���ͻ������Ͻǵ����꣬��ȥrect_ctr.left��
		point.y -= m_CamImageRect.top;//rect_ctr.top�󣬼�Ϊ������Picture�ؼ����Ͻǵ�����

		if (m_points1.size() <= 3)
		{
			if (point.x < 0 || point.x > m_TheImageRect.Width() || point.y < 0 || point.y > m_TheImageRect.Height())
			{
				MessageBox("ѡȡ�ĵ㲻��Ŀ��ͼ��Χ�ڣ�");
			}
			else
			{
				char point_x[5];
				char point_y[5];
				char point_num[5];
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
		}

		if (m_points1.size() >= 4)
		{
			MessageBox("��ͼ��ѡȡ����������Ŀ�Ѿ��ﵽ4��");
			GetDlgItem(IDC_ADUJST)->EnableWindow(TRUE);
			MessageBox("�ɽ��л���Ϣƥ��");
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
	ShowMatImgToWnd(GetDlgItem(IDC_PICTURE), TheImage, proportionPicture);
	//DrawPicToHDC(TheImage, IDC_PICTURE);            // ������ʾͼƬ����    
	UpdateWindow();

	GetDlgItem(IDC_PICTURE_POINT)->EnableWindow(TRUE); // ʹ��ȡ�����㰴ť��Ч
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
	ShowMatImgToWnd(GetDlgItem(IDC_VIDEO), CamImage, proportionVideo);
	//DrawPicToHDC(TheImage, IDC_PICTURE);            // ������ʾͼƬ����    
	UpdateWindow();

	GetDlgItem(IDC_VIDEO_POINT)->EnableWindow(TRUE); // ʹ��ȡ�����㰴ť��Ч
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

	//Newpoints = Refresh_MacthPoints(Points1, Points2);//����ȫ��ͼ���ĸ���ȷƥ��㼯
	Refresh_MacthPoints(Points1, Points2);//����ȫ��ͼ���ĸ���ȷƥ��㼯
	//m_newpoints = Newpoints;
}

// ��ͼ����ʾ����Ӧ��ͼ���
void C����ϢУ׼����Dlg::ShowPointToWnd(CWnd* pWnd, cv::Mat img)
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


// ��ͼ����ʾ����Ӧ��ͼ���
void C����ϢУ׼����Dlg::ShowMatImgToWnd(CWnd* pWnd, cv::Mat img, double *proportion)
{
	if (img.empty())
		return;
	CDC *pDC = pWnd->GetDC();
	HDC hDC = pDC->GetSafeHdc();
	CRect rect;
	pWnd->GetClientRect(&rect);   
	IplImage Iimg = img;
		
	// m_CamImageRect

	int rw = rect.right - rect.left; // ���ͼƬ�ؼ��Ŀ�͸�   
	int rh = rect.bottom - rect.top;   
	int iw = TheImage.cols; // ��ȡԭʼͼƬ�Ŀ�͸�   
	int ih = TheImage.rows;

	// �������ű���
	proportion[0] = rw * 1.0 / iw;
	proportion[1] = rh * 1.0 / ih;

	CvvImage cimg;
	cimg.CopyOf(&Iimg); // ����ͼƬ
	cimg.DrawToHDC(hDC, &rect); // ��ͼƬ���Ƶ���ʾ�ؼ���ָ��������
	ReleaseDC(pDC);
}


//����ͼ����Ϣ�ؼ���
double C����ϢУ׼����Dlg::Entropy(Mat img)
{
	double temp[256] = {0.0}; // ��ʼ��

	// ����ÿ�����ص��ۻ�ֵ
	for (int m = 0; m < img.rows; ++m)
	{// ��Ч�������еķ�ʽ
		const uchar* t = img.ptr<uchar>(m); // ָ��ͼ��ÿһ�е��׵�ַ
		for (int n = 0; n < img.cols; n++)
		{
			int i = t[n];		   // ��õ�ǰ�±������ֵi
			temp[i] = temp[i] + 1; // ͼ��������ֵi���ֵĴ���
		}
	}

	// ����ÿ�����س��ֵĸ���
	for (int i = 0; i < 256; ++i)
	{
		temp[i] /= (img.rows * img.cols); // ����ɸ���
	}

	double result = 0;
	// ����ͼ����Ϣ��
	for (int i = 0; i < 256; ++i)
	{
		if (temp[i] == 0.0)
			result = result;
		else
			result -= temp[i] * (log(temp[i]) / log(2.0));
	}

	return result;

}


// ����ͼ��������Ϣ�ؼ���
double C����ϢУ׼����Dlg::ComEntropy(Mat img1, Mat img2, double img1_entropy, double img2_entropy)
{
	double temp[256][256] = {0.0};


	// ��������ͼ�����ص��ۻ�ֵ
	for (int m1 = 0, m2 = 0; m1 < img1.rows, m2 < img2.rows; ++m1, ++m2)
	{    // ��Ч�������еķ�ʽ
		const uchar* t1 = img1.ptr<uchar>(m1);
		const uchar* t2 = img2.ptr<uchar>(m2);
		for (int n1 = 0, n2 = 0; n1 < img1.cols, n2 < img2.cols; ++n1, ++n2)
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
			temp[i][j] /= (img1.rows * img1.cols);
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
	//img1_entropy = Entropy(img1);
	//img2_entropy = Entropy(img2);
	result = img1_entropy + img2_entropy - result;

	return result;

}


//����ȫ��ͼ���ĸ���ȷƥ��㼯 return vector<CPoint>
void C����ϢУ׼����Dlg::Refresh_MacthPoints(vector<CPoint> points1, vector<CPoint> points2)
{
	points1 = m_points1; // ��Ƶ֡ͼ��ƥ��㼯
	points2 = m_points2; // ȫ��ͼ��ƥ��㼯����ʼƥ��㣬��Ҫ���û���Ϣ�Ӻ�������

	//// Mat TheImage; //ȫ��ͼ
	//// Mat CamImage; //��Ƶ֡ͼ��

	cv::Size mat_size;  // ��ͼ�ĳߴ�
	mat_size.height = 100;
	mat_size.width = 100;

	Mat dst1[4];   // ��Ƶ֡ͼ���Ͻ�ȡ���ĸ������Χ��ͼ
	Mat dst2[4];   // ȫ��ͼ���Ͻ�ȡ���ĸ������Χ��ͼ

	// �����ͼƬ��ʾ�ռ�����ʾ��ͼƬ�Ǿ������ŵ�
	// ���ѡȡ������Ҳ�����ź������
	// ��Ҫ������ת��Ϊʵ��ԭͼ�����꣬��ŵ����±�����
	int Point1_x[4],Point1_y[4], Point2_x[4], Point2_y[4];

	// ȡ��ͼ
	for (int i = 0; i < 4; ++i)
	{
		// ��Ƶ֡ͼ��ȡ��ͼ
		Point1_x[i] = int(points1[i].x / proportionVideo[0] - mat_size.width / 2);
		Point1_y[i] = int(points1[i].y / proportionVideo[1] - mat_size.height / 2);
		Rect rect1(Point1_x[i], Point1_y[i], mat_size.width, mat_size.height);
		CamImage(rect1).copyTo(dst1[i]);

		// ȫ��ͼ��ȡ��ͼ
		Point2_x[i] = int(points2[i].x / proportionPicture[0] - mat_size.width / 2);
		Point2_y[i] = int(points2[i].y / proportionPicture[1] - mat_size.height / 2);
		Rect rect2(Point2_x[i], Point2_y[i], mat_size.width, mat_size.height);
		TheImage(rect2).copyTo(dst2[i]);
		
	}

	/*
	imshow("a1", dst1[0]);
	imshow("b1", dst1[1]);
	imshow("c1", dst1[2]);
	imshow("d1", dst1[3]);
	
	imshow("a2", dst2[0]);
	imshow("b2", dst2[1]);
	imshow("c2", dst2[2]);
	imshow("d2", dst2[3]);
	*/	

	//�����ͼ���ӿ����Ϣ�����Ķ�������������ͼ�Ļ���Ϣ��
	double OneImaEntropy1[4]; //��Ƶ֡ͼ����Ϣ��
	double OneImaEntropy2[4]; //ȫ��ͼ��Ϣ��
	double TwoImaEntropy[4]; //��ʼ����Ϣ��

	for (int i = 0; i < 4; ++i)
	{
		OneImaEntropy1[i] = Entropy(dst1[i]);
		OneImaEntropy2[i] = Entropy(dst2[i]);
		TwoImaEntropy[i] = ComEntropy(dst1[i], dst2[i], OneImaEntropy1[i], OneImaEntropy2[i]);
	}

	// �趨��Ƶ֡ͼ��������뾶
	int ScanScope = 50;
	Mat ScanDst[4];
	vector<CPoint> ScanPoint = points1; // ���������õ������龫ȷ���꣬���ȳ�ʼ��Ϊ�ֶ�ѡȡ������

	for (int i = 0; i < 4; ++i)
	{
		double ScanImaEntropy = 0.0;
		double ScanTwoImaEntropy = 0.0;
		double MaxEntropy = 0.0;

		// �趨��Ƶ֡�ӿ�������߽�
		int left = int(points1[i].x / proportionVideo[0]) - ScanScope;
		int right = int(points1[i].x / proportionVideo[0]) + ScanScope;
		int top = int(points1[i].y / proportionVideo[1]) - ScanScope;
		int bottom = int(points1[i].y / proportionVideo[1]) + ScanScope;

		for (int j = top; j <= bottom; ++j)
		{
			for (int k = left; k <= right; ++k)
			{
				// ��Ƶ֡ͼ������ͼ��������
				int ScanPoint_x = int(k - mat_size.width / 2);
				int ScanPoint_y = int(j - mat_size.height / 2);
				Rect rect2(ScanPoint_x, ScanPoint_y, mat_size.width, mat_size.height);
				CamImage(rect2).copyTo(ScanDst[i]);

				// ���¼���������ͼ��ȫ��ͼ��Ӧ�����������
				ScanImaEntropy = Entropy(ScanDst[i]);
				ScanTwoImaEntropy = ComEntropy(dst2[i], ScanDst[i], OneImaEntropy2[i], ScanImaEntropy);

				if (ScanTwoImaEntropy > MaxEntropy)
				{
					// MessageBox("�о�ȷƥ���");
					MaxEntropy = ScanTwoImaEntropy;
					ScanPoint[i].x = k;
					ScanPoint[i].y = j;
				}
			}
		}	
	}

	// ��ȷɨ�������ȡ��ͼ
	Mat dstRes[4];
	for (int i = 0; i < 4; ++i)
	{
		// ��Ƶ֡ͼ������ȡ��ȷ��ͼ
		int Point1_x = int(ScanPoint[i].x - mat_size.width / 2);
		int Point1_y = int(ScanPoint[i].y - mat_size.height / 2);
		Rect rect2(Point1_x, Point1_y, mat_size.width, mat_size.height);
		CamImage(rect2).copyTo(dstRes[i]);
		
	}

	/*
	// ��ȷ�������Χ������ʾ
	imshow("a3", dstRes[0]);
	imshow("b3", dstRes[1]);
	imshow("c3", dstRes[2]);
	imshow("d3", dstRes[3]);
	*/

	// ���ϵó��ĶԾ�ȷ��ƥ��㣬���½���ͶӰ�任�ļ���
	// ʹ�ú���getPerspectiveTransform(const Point2f src[], const Point2f dst[]) 
	// http://blog.csdn.net/xiaowei_cqu/article/details/26478135

	vector<Point2f> corners(4); 
	vector<Point2f> corners_trans(4); 

	// ��Ƶ֡ͼ����ĸ���ȷƥ���
	corners[0] = Point2f(ScanPoint[0].x, ScanPoint[0].y);  
    corners[1] = Point2f(ScanPoint[1].x, ScanPoint[1].y);  
    corners[2] = Point2f(ScanPoint[2].x, ScanPoint[2].y);  
    corners[3] = Point2f(ScanPoint[3].x, ScanPoint[3].y);

	// ȫ��ͼ�϶�Ӧ���ĸ���
	corners_trans[0] = Point2f(Point2_x[0], Point2_y[0]);  
    corners_trans[1] = Point2f(Point2_x[1], Point2_y[1]);  
    corners_trans[2] = Point2f(Point2_x[2], Point2_y[2]);  
    corners_trans[3] = Point2f(Point2_x[3], Point2_y[3]);

	cv::Mat transform = getPerspectiveTransform(corners, corners_trans);  // ���ͶӰ�任����

    Mat img_trans;

	warpPerspective(CamImage, img_trans, transform, CamImage.size(), INTER_LINEAR, BORDER_CONSTANT);

    imwrite("ת�������Ƶ֡ͼ��.BMP", img_trans); 
	imshow("ת�������Ƶ֡ͼ��", img_trans);

}

