#pragma once

/**
* 定义事件ID宏定义，用于简化事件定义
*
* 用法：
* 1、EVENT_TYPE_DECL 与 EVENT_TYPE_STR_DECL 用于声明事件ID
* 2、EVENT_TYPE_DEFINE 与 EVENT_TYPE_STR_DEFINE 用于定义指定的事件ID
*
* EVENT_TYPE_DECL与EVENT_TYPE_DEFINE 用于定义通用类型的事件ID
* 定义一个类型为int型的事件ID的方法：
* 1> 在头文件中声明具体的ID名：EVENT_TYPE_DECL( int, TEST );
* 2> 在源文件中定义具体的ID值：EVENT_TYPE_DEFINE( int, TEST, 10 );
*
* EVENT_TYPE_STR_DECL和EVENT_TYPE_STR_DEFINE 则被用于定义字符串类型的事件ID
* 定义一个字符串类型的事件ID的方法：
* 1> 在头文件中声明具体的ID名：EVENT_TYPE_STR_DECL( TEST ); // 等价于 EVENT_TYPE_DECL( char * const, TEST );
* 2> 在源文件中定义具体的ID值：EVENT_TYPE_STR_DEFINE( TEST, "test" ); // 等价于 EVENT_TYPE_DEFINE( char * const, TEST, "test" );
*
* @zhongzhihua 2015.12.29
**/

#define EVENT_TYPE_DECL( valType, valName )	\
	extern const valType valName
#define EVENT_TYPE_DEFINE( valType, valName, valValue )		\
	const valType valName = valValue

#define EVENT_TYPE_STR_DECL( valName )		\
	EVENT_TYPE_DECL( char * const, valName )
#define EVENT_TYPE_STR_DEFINE( valName, valValue )		\
	EVENT_TYPE_DEFINE( char * const, valName, valValue )

