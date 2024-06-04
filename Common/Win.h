#pragma once
#include <Windows.h>
#include "include/core/SkPaint.h"
#include "include/core/SkCanvas.h"
#include "src/base/SkAutoMalloc.h"
extern "C" {
#include <quickjs.h>
}
class Win
{
public:
	static void Reg(JSContext* ctx);
	~Win();
private:
	static LRESULT CALLBACK RouteWindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static JSValue constructor(JSContext* ctx, JSValueConst new_target, int argc, JSValueConst* argv);
	Win();
	void initWindow();
	void paintWindow();
	void initCanvas();


	static JSValue setPos(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);
	static JSValue setPosCenterScreen(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);
	static JSValue fillColor(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv);


	int x, y, w, h;
	HWND hwnd;
	std::unique_ptr<SkCanvas> canvas;
	SkAutoMalloc surfaceMemory;
};
