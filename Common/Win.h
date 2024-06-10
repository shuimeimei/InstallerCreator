#pragma once
#include <Windows.h>
#include "include/core/SkPath.h"
#include "include/core/SkPaint.h"
#include "include/core/SkCanvas.h"
#include "src/base/SkAutoMalloc.h"
#include <vector>
#include <map>

extern "C" {
#include <quickjs.h>
}
class Win
{
public:
	static void Reg(JSContext* ctx);
	~Win();
private:
	Win();
	static Win* getPtr(JSValue& val);
	static LRESULT CALLBACK RouteWindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	void initWindow(std::wstring& title);
	void paintWindow();
	void initCanvas();
	void show();

	static JSValue constructor(JSContext* ctx, JSValueConst new_target, int argc, JSValueConst* argv);
	static JSValue show(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);
	static JSValue refresh(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);
	static JSValue addEventListener(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);
	//SizePos
	static void regSizePos(JSContext* ctx, JSValue& proto);
	static JSValue setPos(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);
	static JSValue getPos(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);
	static JSValue setSize(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);
	static JSValue getSize(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);
	static JSValue setCaptionPath(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);
	static JSValue setPosCenterScreen(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);
	//Draw
	static void regDraw(JSContext* ctx, JSValue& proto);
	static JSValue fillColor(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);
	static JSValue drawRect(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);
	static JSValue drawEllipse(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);
	static JSValue drawShadow(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);
	static JSValue drawText(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);
	//Timer
	static void regTimer(JSContext* ctx, JSValue& proto);
	static void CALLBACK timeoutProc(HWND hWnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);
	static void CALLBACK intervalProc(HWND hWnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);
	static JSValue setTimeout(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);
	static JSValue setInterval(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);
	static JSValue clearTimeout(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);
	static JSValue clearInterval(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);


	int x, y, w{ 1200 }, h{800};
	float scaleFactor;
	HWND hwnd;
	std::unique_ptr<SkCanvas> canvas;
	SkAutoMalloc surfaceMemory;
	std::vector<JSValue> printCB;
	HDC hCompatibleDC = NULL;
	HBITMAP bottomHbitmap;
	SkPath captionPath;
	bool isCaptionMouseDown{false};
	POINT startPos;
};

