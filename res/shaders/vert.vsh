//attribute是从外部传进来的;
attribute vec4 a_position;
attribute vec4 a_color;

//varying类型的变量是在vertex shader和fragment shader之间传递数据用的;
varying vec4 v_fragmentColor;

//每一个Shader程序都有一个main函数;
void main()
{
	gl_Position = CC_MVPMatrix * a_position
	v_fragmentColor = a_color;
}