#include <stdio.h>
#include <malloc.h>


struct Student
{
    int sid;
    int age;
};


struct Student * Create(void);
void Show(struct Student *);

int main(void)
{
    struct Student * stu;
    stu = Create();
    Show(stu);

    //free(stu);
    return 0;

}


void Show(struct Student * stu)
{
    if(stu != NULL){
        printf("%d %d\n", stu->sid, stu->age);
        free(stu);
    }
    return;
}


struct Student * Create()
{
    struct Student * stu = (struct Student *)malloc(sizeof(struct Student));

    //stu->sid = 99;
    //stu->age = 77;

    return stu;
}
