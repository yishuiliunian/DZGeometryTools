//
//  DZLayoutAngle.h
//  Pods
//
//  Created by baidu on 2017/1/17.
//
//

#ifndef DZLayoutAngle_h
#define DZLayoutAngle_h
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




#endif /* DZLayoutAngle_h */
