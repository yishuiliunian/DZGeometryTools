//
//  DZGeometryTools.h
//  TimeUI
//
//  Created by Stone Dong on 13-12-10.
//  Copyright (c) 2013年 Stone Dong. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

//角度转化

/**
 将弧度表示转化为角度表示

 @param x 弧度
 @return 对应的角度
 */
#define DEGREE_TO_ANGLE(x) (x / 180.0f * M_PI)


/**
 将角度表示转化为弧度表示

 @param x 角度
 @return 对应的弧度
 */
#define ANGLE_TO_DEGREE(x) (x * 180.0f / M_PI)

//


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

#ifdef __cplusplus
extern "C"
{
#endif
    

#pragma mark Point Functions
    /**
     计算两个点之间的距离

     @param p1 起始点
     @param p2 结束点
     @return 两个点之间的距离
     */
    float CGDistanceBetweenPoints(CGPoint p1, CGPoint p2);
#pragma mark Size Functions
    
#pragma mark Rect Functions
    /**
     *  计算一个指定大小居中对齐时在指定区域的位置
     *
     *  @param rect 指定的区域
     *  @param size 指定大小
     *
     *  @return 指定大小居中对齐时在指定区域的位置
     */
    CGRect CGRectCenter(CGRect rect, CGSize size);
    

    
    /**
     对一个区域施加edge扩展，并返回得到的新区域

     @param parent 原始区域
     @param edge 将要扩展的四个边的情况
     @return 扩展之后的新区域
     */
    CGRect CGRectUseEdge(CGRect parent, UIEdgeInsets edge);
    
    
    /**
     以制定的中心点为中心进行三维变化

     @param t 原始的三维变化
     @param center 中心店
     @param disZ z轴偏移
     @return 计算好的三维变化
     */
    CATransform3D CATransform3DPerspect(CATransform3D t, CGPoint center, float disZ);
    
    
    /**
     以制定的中心点为中心对标砖转化进行三维转化

     @param center 中心点
     @param disZ z轴偏移
     @return 计算好的三维变化
     */
    CATransform3D CATransform3DMakePerspective(CGPoint center, float disZ);
    
    
    /**
     *  减去一个指定的大小，并返回计算后的区域
     *
     *  @param rect 原始区域
     *  @param size 需要减去的大小
     *
     *  @return 减去指定大小的区域
     */
    CGRect CGRectCenterSubSize(CGRect rect, CGSize size);
    
    

    
    /**
     计算并返回一个区域的中心点坐标
     
     @param rect 需要计算的区域
     @return 区域的中心点坐标
     */
    CGPoint CGRectGetCenter(CGRect rect);
    
    
    /**
     在指定的Point基础上施加偏移

     @param p1 原始的Point
     @param p2 需要施加的偏移量
     @return 施加偏移之后的新Point
     */
    CGPoint CGPointSubtraction(CGPoint p1, CGPoint p2);
    
    
    /**
     在指定的Size基础上施加偏移

     @param originSize 原始的Size
     @param aimSize 偏移量
     @return 施加偏移之后的size
     */
    CGSize CGSizeScaleToSize(CGSize originSize, CGSize aimSize);
    
    
    /**
     在指定的Size基础上进行缩放

     @param size 原始的Size
     @param scale 需要缩放的比例
     @return 缩放之后的Size
     */
    CGSize CGSizeScale(CGSize size, CGFloat scale);
    
    /**
     
     计算一个Size在Rect中的居中对齐的位置

     @param rect 父区域
     @param size 需要布局的区域大小
     @return 目标size在父区域中的位置
     */
    CGRect CGRectOfCenterForContainsSize(CGRect rect , CGSize size);
    
    
    /**
     一个index是否在Range范围之内

     @param range 区域
     @param index 坐标
     @return  一个index是否在Range范围之内
     */
    BOOL NSRangeCotainsIndex(NSRange range, NSInteger index);
    //
    
    
    /**
     打印一个Rect
     */
    void LogCGRect(NSString* prefix, CGRect rect);
    
    
    /**
     打印一个Point
     */
    void LogCGPoint(NSString* prefix, CGPoint point);
    
    
    /**
     打印一个Size
     */
    void LogCGSize(NSString* prefix, CGSize point);

    
    /**
     以指定坐标为重点点向四周扩展指定大小，计算并得到区域位置

     @param pint 中心点坐标
     @param aimSize 目标区域大小
     @return 目标区域坐标
     */
    CGRect CGRectExpandPoint(CGPoint point , CGSize aimSize);
    
    
    /**
     @return 当前设备的屏幕大小
     */
    CGSize CGCurrentScreenSize();
    
    
    /**
     @return 当前屏幕是否支持Retina技术
     */
    BOOL CGScrrentIsRetina();
    
    

    
    
    /**
     对指定区域实施y轴方向上的偏移

     @param rect 原始区域
     @param height 偏移量
     @return 目标区域
     */
    CGFloat CGRectHeightOffsetCenter(CGRect rect , CGFloat offset);
    
    
    /**
     对目标区域实施x轴方向上的偏移

     @param rect 原始区域
     @param width 偏移量
     @return 目标区域
     */
    CGFloat CGRectWidthOffsetCenter(CGRect rect , CGFloat width);
    /**
     *  按照指定方向对Rect进行压缩
     *
     *  @param origin 原始的Rect
     *  @param offset 需要压缩的距离
     *  @param edge   压缩方向
     *
     *  @return 压缩好的Rect
     */
    CGRect CGRectShrink(CGRect origin, CGFloat offset, CGRectEdge edge);
    
    /**
     *  将一个Rect横向切割成多个
     *
     *  @param origin 原始REct
     *  @param rects  输出的rect们
     *  @param count  数量
     *  @param space  间距
     */
    void CGRectHorizontalSplit(CGRect origin, CGRect rects[], int count, CGFloat space);
    
    /**
     *  将一个Rect垂直切割成多个
     *
     *  @param origin 原始REct
     *  @param rects  输出的rect们
     *  @param count  数量
     *  @param space  间距
     */
    void CGRectVerticalSplit(CGRect origin, CGRect rects[], int count, CGFloat space);
    
    /**
     *  按照指定方向将一个Size偏移到参照Rect的对应位置
     *
     *  @param rect   参照Rect
     *  @param size   需要偏移的Size
     *  @param margin 中间的间距
     *  @param edge   指定方向
     *
     *  @return 偏移好的Rect
     */
    CGRect CGRectCenterOffsetSize(CGRect rect, CGSize size, CGFloat margin,  CGRectEdge edge);
    
    /**
     *  计算右下角的一个Rect
     *
     *  @param originRect 原始的Rect
     *  @param size       需要承载的Rect的大小
     *
     *  @return 返回大小为size位于originRect右下角的Rect
     */
    CGRect CGRectBottomRightCorner(CGRect originRect,  CGSize size);
    
    
    /**
     对size按照宽度进行缩放

     @param size 原始size
     @param width 目标size的宽度
     @return 目标size
     */
    CGSize CGSizeAlignWidth(CGSize size, CGFloat width);
    
    
    
    /**
     对size按照高度进行缩放

     @param size 原始size
     @param height 目标size的高度
     @return 目标size
     */
    CGSize CGSizeAlignHeight(CGSize size, CGFloat height);
    
    /**
     Cell初始化的时候的默认布局大小

     @return Cell的默认布局大小
     */
    
#define CGRectDefaultCell CGRectInitialCell()
    CGRect CGRectInitialCell();
   static  inline CGRect CGRectAlignInterge(CGRect rect) {
        CGRect aimRect = rect;
        aimRect.size.width = floor(rect.size.width);
        aimRect.size.height = floor(rect.size.height);
        aimRect.origin.x = floor(rect.origin.x);
        aimRect.origin.y = floor(aimRect.origin.y);
        return aimRect;
    }
    
#pragma mark -------DEPRECATED-------
    /**
     *  打印一个CGRect
     *
     *  @param rect 要打印的CGRect
     */
    void CGPrintRect(CGRect rect ) __deprecated_msg("API upgrade plase use LogCGRect");
    
    /**
     *  打印一个CGRect,并显示特定的key
     *
     *  @param rect 要打印的CGRect
     */
    void CGPrintKeyRect(NSString* prefixKey, CGRect rect ) __deprecated_msg("接口升级废弃，请使用LogCGRect(NSString *prefix, CGRect rect)");
    
    
    /**
     打印一个Point
     
     @param point 需要打印的Point
     */
    void CGPrintPoint(CGPoint point) __deprecated_msg ("接口升级废弃，请使用LogCGPoint(NSString *prefix, CGPoint point)");
    
    
    /**
     计算并返回一个区域的中心点坐标
     
     @param rect 需要计算的区域
     @return 区域的中心点坐标
     */
    CGPoint CGPointCenterRect(CGRect rect)  __deprecated_msg("接口升级废弃了，请使用CGRectGetCenter");
    
    
    /**
     对一个区域施加edge扩展，并返回得到的新区域
     
     @param parent 原始区域
     @param edge 将要扩展的四个边的情况
     @return 扩展之后的新区域
     */
    CGRect CGRectWithEdgeInsetsForRect(UIEdgeInsets edge, CGRect rect) __deprecated_msg("接口升级废弃了，请使用CGRectUseEdge");
    
    CGFloat CGPointDistance(CGPoint p1, CGPoint p2)  __deprecated_msg("接口升级废弃了，请使用CGDistanceBetweenPoints");
    /**
     @return 当前屏幕像素点背书
     */
    CGFloat CGPixMultiFactor() __deprecated_msg("废弃，直接使用UIScreen scale");
    
    
    /**
     @return 当前屏幕像素密度
     */
    CGSize CGCurrentRealPixSize() __deprecated_msg("废弃");
    
    
#ifdef __cplusplus
}
#endif

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



//顶部固定高度，铺满width的布局
#define LAYOUT_VIEW_BOTTOM_FILL_WIDTH(view, sView__, xMargin, yMargin, refHeight__)  CGRect rect##view = CGRectZero;\
rect##view.origin.x = xMargin;\
rect##view.origin.y = CGRectGetHeight(sView__.bounds) - refHeight__;\
rect##view.size.width = CGRectGetWidth(sView__.bounds) - xMargin*2;\
rect##view.size.height = refHeight__ - yMargin;\
view.frame = rect##view;

#define LAYOUT_SUBVIEW_BOTTOM_FILL_WIDTH(view, xMargin, yMargin, refHeight__)  LAYOUT_VIEW_BOTTOM_FILL_WIDTH(view, self, xMargin, yMargin, refHeight__)

#define LAYOUT_SUBVIEW_CENTER(view, refSV, xMargin ,yMargin)  view.frame = CGRectCenter(refSV.bounds, CGSizeMake(CGRectGetWidth(refSV.bounds) - xMargin*2,CGRectGetHeight(refSV.bounds) - yMargin*2));

