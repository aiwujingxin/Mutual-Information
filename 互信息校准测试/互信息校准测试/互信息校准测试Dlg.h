
// ����ϢУ׼����Dlg.h : ͷ�ļ�
//

#pragma once
#include "cv.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/core.hpp>
#include "opencv2/calib3d/calib3d.hpp"
#include "highgui.h"
#include "CvvImage.h"
#include <vector>
#include "afxwin.h"

using namespace cv;
using namespace std;


// C����ϢУ׼����Dlg �Ի���
class C����ϢУ׼����Dlg : public CDialogEx
{
// ����
public:
	C����ϢУ׼����Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:


	vector<CPoint> m_newpoints; // ��Ҫ���û���Ϣ�Ӻ������µõ���ƥ��㼯��Ҫ���ĸ��� 
	vector<CPoint> m_points1;// ��Ƶ֡ͼ��ƥ��㼯��Ҫ���ĸ���
	vector<CPoint> m_points2;// ȫ��ͼ��ƥ��㼯����ʼƥ��㼯��Ҫ���ĸ���

	Mat TheImage; //ȫ��ͼ
	Mat CamImage; //��Ƶ֡ͼ��

	CStatic m_TheImage;//��ȫ��ͼ�������ʾ����
	CStatic m_CamImage;//����Ƶ֡ͼ��������ʾ����

	CRect m_TheImageRect;//��ʾȫ�����ڵľ��δ�
	CRect m_CamImageRect;//��ʾ��Ƶ���ڵľ��δ�

	

	CvCapture *capture;


public:
	BOOL m_PicturePointdownflag; //ȫ��ͼ����ѡȡ���λ
	BOOL m_VideoPointdownflag;  //��Ƶ֡ͼ������ѡȡ���λ


public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedOpenPicture();
	afx_msg void OnBnClickedOpenVideo();
	afx_msg void OnBnClickedPicturePoint();
	afx_msg void OnBnClickedVideoPoint();
	afx_msg void OnBnClickedAdujst();

public:

	void ShowMatImgToWnd(CWnd* pWnd, cv::Mat img);

	double Entropy(Mat img);//����ͼ����Ϣ�ؼ���	
	double ComEntropy(Mat img1, Mat img2, double img1_entropy, double img2_entropy);// ����ͼ��������Ϣ�ؼ���	
	vector<CPoint> Refresh_MacthPoints(vector<CPoint> points1, vector<CPoint> points2);//����ȫ��ͼ���ĸ���ȷƥ��㼯


};
