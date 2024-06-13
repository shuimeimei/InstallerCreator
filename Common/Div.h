#pragma once
#include <string>
#include "include/core/SkFont.h"
#include "Rect.h"


class Div:public Rect
{
public:
	static void Reg(JSContext* ctx);
	~Div(); 
	void Paint(Win* win) override;
private:
	Div();
	static JSValue constructor(JSContext* ctx, JSValueConst newTarget, int argc, JSValueConst* argv);
	static JSValue newLTRB(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);
	static JSValue newXYWH(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);
	static JSValue setText(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);
	static JSValue setAlign(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);
	static JSValue setTextColor(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);
	static JSValue setFontSize(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);
	static JSValue setFontFamily(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);
	std::wstring  text;
	const char* iconCode;
	SkFont* font;
	float fontSize;
	unsigned int color;
	unsigned int verticalAlign;  //����
	unsigned int horizontalAlign; //����
	bool isIcon{false};
};