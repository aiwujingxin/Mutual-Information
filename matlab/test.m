% ����任
clear;
q = 0.5;
U = [1*cos(q) 1.1*sin(q) 0;-1.1*sin(q) 1*cos(q) 0;0 0 1];
img = imread('Fig8.14(a).jpg');
% ��ȡͼ�������Ϣ
% ��Ϊ��ɫͼ������ת��Ϊ�Ҷ�ͼ��
Info = imfinfo('Fig8.14(a).jpg'); 
if (Info.BitDepth > 8)
    img = rgb2gray(img);
end
imwrite(img, 'new1.jpg');
% Maketform�����������ø����Ĳ��������任�ṹ
% Ȼ��Ѹñ任�ṹ�����ṹ��任
% ���ݵõ��Ľṹ�����T����imtransform�������б任��
T = maketform('affine',U); 
% ����A��Ҫ�任��ͼ��T����makeform���������ı任�ṹ
[imt,xdata,ydata] = imtransform(img,T);%,'XYScale',1);
imwrite(imt, 'new2.jpg');