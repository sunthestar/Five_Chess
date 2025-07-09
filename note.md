# Define

```
p				//结构体-> 当前焦点    成员：x，y 坐标
focus			//封装-> 指向当前焦点的指针
Map[][]			//显示的棋盘数组
Chess_Flag		//当前棋子颜色标志位
Decide[][]		//真实的棋盘数组，用于胜负判定
Message[]		//消息数组，用于提示用户消息
```

# Key

## void Key_Scan()
	检测键盘输入并进行逻辑处理

# Login

## void Focus_Move(Point* focus);
	focus：当前焦点指针
	焦点移动逻辑判断并刷新棋盘显示
## void Chess_Falling(Point* focus);
	focus：当前焦点的指针
	玩家落子逻辑判断并刷新棋盘显示
## void Is_Win(int x, int y);
	x：当前焦点的x坐标换算后在Decide数组中的x坐标
	y：当前焦点的y坐标换算后在Decide数组中的y坐标
	胜负判定

# Map

## void Map_Init();
	初始化棋盘
## void Map_Flush();
	焦点移动时重置上一次棋盘的改动
## void Map_Move(char* Map, int s, int len);
	Map：要修改的棋盘列数组
	s：要移动的起始位置
	len：数组最后"\0"所占的位置
	将指定位置的数据往后移动一格（因为棋盘和棋子占两个字节，空格只占一个字节，不改变数组长度的情况下进行数据替换会导致数据排列乱掉）

# Show

## void show();
	显示棋盘

# ReadMe
	写在最后
	
