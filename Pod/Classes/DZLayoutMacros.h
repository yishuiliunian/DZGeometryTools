//
//  DZLayoutMacros.h
//  Pods
//
//  Created by baidu on 2017/1/17.
//
//

#ifndef DZLayoutMacros_h
#define DZLayoutMacros_h

/* 返回View的宽度 */
#define CGRectViewWidth (CGRectGetWidth(self.bounds))


/**
 返回View的高度
 */
#define CGRectViewHeight CGRectGetHeight(self.bounds)


/**
 返回UIViewController的rootView的宽度
 //
 在新版本中废弃
 */
#define CGRectVCWidth (CGRectGetWidth(self.view.bounds))

/**
 返回UIViewController的rootView的高度
 //
 在新版本中废弃
 */
#define CGRectVCHeight CGRectGetHeight(self.view.bounds)


/**
 返回UIViewController的rootView的宽度
 */
#define CGRectGetViewControllerWidth (CGRectGetWidth(self.view.frame))

/**
 返回UIViewController的rootView的高度
 */
#define CGRectGetViewControllerHeight (CGRectGetHeight(self.view.frame))


#define CGRectSetX(rect, x) CGRectMake(x, CGRectGetMinY(rect), CGRectGetWidth(rect), CGRectGetHeight(rect));
#define CGRectSetY(rect, y) CGRectMake(CGRectGetMinX(rect), y, CGRectGetWidth(rect), CGRectGetHeight(rect));
#define CGRectSetWidth(rect, width) CGRectMake(x , y, width , CGRectGetHeight(rect));
#define CGRectSetHeight(rect, height) CGRectMake(x, y, CGRectGetWidth(rect), width);

#define LAYOUT_View_Frame(view, x, y , width, height) view.frame = CGRectMake(x,y, width, height)
#define LAYOUT_SubView_Fill(view) view.frame = self.bounds


#define MARGIN_LEFT left
#define MARGIN_RIGHT right
#define MARGIN_ALL all


#define MARGIN_NAME_X(subfix) margin_x_##subfix
#define MARGIN_NAME_Y(subfix) margin_y_##subfix


#define MARGIN_NAME_X_ALL MARGIN_NAME_X(MARGIN_X_ALL)


#define LAYOUT_DEFINE_MARGIN_X(subfix, x) static float MARGIN_NAME_X(subfix)  = x
#define LAYOUT_DEFINE_MARGIN_Y(subfix, y) static float MARGIN_NAME_Y(subfix)  = y
#define LAYOUT_DEFINE_MARGIN_X_ALL(x) LAYOUT_DEFINE_MARGIN_X(MARGIN_ALL,x)
#define LAYOUT_DEFINE_MARGIN_Y_ALL(x) LAYOUT_DEFINE_MARGIN_Y(MARGIN_ALL,x)


#define LAYOUT_RECT_ORIGIN_RELY_MIN_X(rect, view, margin_x) rect.origin.x = CGRectGetMinX(view.frame) + margin_x
#define LAYOUT_RECT_ORIGIN_RELY_MAX_X(rect, view, margin_x) rect.origin.x = CGRectGetMaxX(view.frame) + margin_x
#define LAYOUT_RECT_ORIGIN_RELY_MIN_Y(rect, view, margin_y) rect.origin.y = CGRectGetMinY(view.frame) + margin_y
#define LAYOUT_RECT_ORIGIN_RELY_MAX_Y(rect, view, margin_y) rect.origin.y = CGRectGetMaxY(view.frame) + margin_y


#define LAYOUT_VIEW_RELY_MAX_X_Y(view, xRV, xMargin,yRV, yMargin,  width_, height_) CGRect rect##view = CGRectZero;\
LAYOUT_RECT_ORIGIN_RELY_MAX_X(rect##view, xRV, xMargin);\
LAYOUT_RECT_ORIGIN_RELY_MAX_Y(rect##view, yRV, yMargin);\
rect##view.size.width = width_;\
rect##view.size.height = height_;


//y依赖于顶部元素，并且尽可能填充满width的布局
#define LAYOUT_SUBVIEW_FILL_WIDTH_RELY_MAX_Y(view, supView, xMargin, yRV, yMargin, height__) CGRect rect##view = CGRectZero;\
LAYOUT_RECT_ORIGIN_RELY_MAX_Y(rect##view, yRV, yMargin);\
rect##view.size.width = CGRectGetWidth(supView.frame) - xMargin*2;\
rect##view.origin.x = xMargin;\
rect##view.size.height = height__;\
view.frame = rect##view;

#define LAYOUT_VIEW_FILL_WIDTH_RELY_MAX_Y(view, xMargin, yRV, yMargin, height__)\
LAYOUT_SUBVIEW_FILL_WIDTH_RELY_MAX_Y(view, self, xMargin, yRV, yMargin, height__)

//顶部固定高度，铺满width的布局
#define LAYOUT_VIEW_TOP_FILL_WIDTH(view, sView__, xMargin, yMargin, refHeight__)  CGRect rect##view = CGRectZero;\
rect##view.origin.x = xMargin;\
rect##view.origin.y = yMargin;\
rect##view.size.width = CGRectGetWidth(sView__.bounds) - xMargin*2;\
rect##view.size.height = refHeight__ - yMargin;\
view.frame = rect##view;

#define LAYOUT_SUBVIEW_TOP_FILL_WIDTH(view, xMargin, yMargin, refHeight__)  LAYOUT_VIEW_TOP_FILL_WIDTH(view, self, xMargin, yMargin, refHeight__)



//底部固定高度，铺满width的布局
#define LAYOUT_VIEW_BOTTOM_FILL_WIDTH(view, sView__, xMargin, yMargin, refHeight__)  CGRect rect##view = CGRectZero;\
rect##view.origin.x = xMargin;\
rect##view.origin.y = CGRectGetHeight(sView__.bounds) - refHeight__;\
rect##view.size.width = CGRectGetWidth(sView__.bounds) - xMargin*2;\
rect##view.size.height = refHeight__ - yMargin;\
view.frame = rect##view;

#define LAYOUT_SUBVIEW_BOTTOM_FILL_WIDTH(view, xMargin, yMargin, refHeight__)  LAYOUT_VIEW_BOTTOM_FILL_WIDTH(view, self, xMargin, yMargin, refHeight__)

#define LAYOUT_SUBVIEW_CENTER(view, refSV, xMargin ,yMargin)  view.frame = CGRectCenter(refSV.bounds, CGSizeMake(CGRectGetWidth(refSV.bounds) - xMargin*2,CGRectGetHeight(refSV.bounds) - yMargin*2));



#endif /* DZLayoutMacros_h */
