# ����QuickJS
- clone QuickJS�Ĵ��룺https://github.com/quickjs-ng/quickjs
- ����CMAKE����̬���ӣ�������VS����
- �޸�MT/MTD �ٱ�����Ŀ
- �޸�quickjs.h�ļ�(��Ȼ�޷���C++������ʹ�����ͷ�ļ�)
	- 482�У�return { .u{.int32 = val }, .tag{JS_TAG_BOOL} };
	- 488�У�return { .u{.int32 = val }, .tag{JS_TAG_INT} };
	- 499�У� return { .u{.int32 = val }, .tag{JS_TAG_CATCH_OFFSET} };

# ����Skia

- ����Ҫ����third_party/external�µĿ�
- ����Ҫ����icu:skia_use_icu=false
```
bin/gn gen out/debug --args='clang_win=\"C:\Program Files\LLVM\" cc=\"clang\" cxx=\"clang++\" extra_cflags=[\"/MTd\"] is_official_build=true is_debug=false skia_use_system_expat=false skia_use_system_libjpeg_turbo=false skia_use_system_libpng=false skia_use_system_libwebp=false skia_use_system_zlib=false skia_use_system_harfbuzz=false skia_use_system_icu=true skia_enable_skparagraph=true skia_enable_skshaper=true skia_enable_skunicode=false skia_use_icu=false'
```
```
bin/gn gen out/release --args='clang_win=\"C:\Program Files\LLVM\" cc=\"clang\" cxx=\"clang++\" extra_cflags=[\"/MT\"] is_debug=false is_official_build=true skia_use_system_expat=false skia_use_system_libjpeg_turbo=false skia_use_system_libpng=false skia_use_system_libwebp=false skia_use_system_zlib=false skia_use_system_harfbuzz=false skia_use_icu=false skia_enable_skparagraph=true skia_enable_skshaper=true skia_enable_skunicode=true'
```