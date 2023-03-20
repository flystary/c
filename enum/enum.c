#include<stdio.h>

/*
enum　枚举名　{枚举元素1,枚举元素2,……};
*/

// #define MON 1
// #define TUE 2
// ....
// #define SUM 7

/*
enum DAY
{
    MON = 1, TUE, WED, THU, FRI, SAT, SUM
};

enum season {spring, summer=3, autumn, winter};


enum DAY
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
};
enum DAY day;

enum DAY
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
} day;

enum
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
} day;

*/

/*
enum DAY
{
    MON=1, TUE, WED, THU, FRI, SAT, SUN
} day;

void day()
{
    enum DAY day;
    day = WED;
    printf("%d\n", day);
}
*/

/*
enum DAY
{
    MON=1, TUE, WED, THU, FRI, SAT, SUN
} day;

void loop()
{
    for (day = MON; day <= SUN; day++) {
        printf("%d\n", day);
    }
}

int main()
{
    // day();
    loop();
    return 0;
}
*/

// enum {
//     ENUM_0,
//     ENUM_10 = 10, // 无法遍历
//     ENUM_11,
// }

#include<stdlib.h>

void color()
{
    enum color { red=1, green, blue };
    enum color favorite_color;

    // 用户输入数字来选择颜色
    printf("请输入你喜欢的颜色: (1. red, 2. green, 3. blue): ");
    scanf("%u", &favorite_color);

    switch (favorite_color)
    {
    case red:
        printf("你喜欢的颜色是红色\n");
        break;
    case green:
        printf("你喜欢的颜色是绿色\n");
        break;
    case blue:
        printf("你喜欢的颜色是蓝色\n");
        break;
    default:
        printf("你没有选择你喜欢的颜色\n");
    }
}

void week()
{
    enum day
    {
        saturday,
        sunday,
        monday,
        tuesday,
        wednesday,
        thursday,
        friday
    } workday;

    int a = 5;
    enum day weekend;
    weekend = ( enum day ) a;  //类型转换
    //weekend = a; //错误
    printf("weekend: %d\n",weekend);
}

int main()
{
    // color();
    week();
    return 0;
}