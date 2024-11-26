// // #include <stdlib.h>
// // #include <sys/types.h>
// // #include <unistd.h>
// // #include <stdio.h>
// // #include <sys/wait.h>

// // // cd mnt/c/Users/msi/Desktop/os_lab_2019/lab4/src
// // int main() {
// //     pid_t childPid = fork();

// //     if (childPid > 0){
// //         printf("Paranet Proccess: %d\n",getpid());
// //         sleep(10);
// //         printf("Sleepinf for 10 seconds...\n");
// //         int status;
// //         //wait(&status);
// //         printf("Child Proccess has been killed\n");
// //     }

// //     else if (childPid == 0){
// //         printf("Child Proccess: %d\n",childPid);
// //         exit(0);
// //     }

// //     else {
// //         perror("Proccess error!\n");
// //         exit(1);
// //     }
// //     return 0;
// // }

// // #include <stdio.h>
// // #include <stdlib.h>
// // #include <unistd.h>
// // #include <signal.h>

// // void alarm_handler(int sig) {
// //     printf("Время вышло! Получен сигнал SIGALRM.\n");
// //     exit(0);
// // }

// // int main() {
// //     signal(SIGALRM, alarm_handler);  // Устанавливаем обработчик для SIGALRM
// //     alarm(3);  // Таймер на 3 секунды
// //     while(1) {
// //         printf("Ожидаю сигнал...\n");
// //         sleep(1);
// //     }
// //     return 0;
// // }


// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// #include <unistd.h>
// #include <errno.h>
// #include <string.h>

// int main() {
//     pid_t pid = fork();  // Создаем дочерний процесс

//     if (pid < 0) {
//         // Ошибка при создании дочернего процесса
//         perror("fork");
//         exit(1);
//     } else if (pid == 0) {
//         // Дочерний процесс
//         printf("Дочерний процесс. Я буду завершаться через 5 секунд...\n");
//         sleep(5);  // Дочерний процесс "работает" 5 секунд
//         exit(0);   // Дочерний процесс завершился
//     } else {
//         // Родительский процесс
//         printf("Родительский процесс. Я не буду сразу вызывать wait(), чтобы оставить зомби процесс.\n");

//         // Родитель продолжает работать и не вызывает wait()
//         sleep(2);  // Даем дочернему процессу время, чтобы он стал зомби (завершился, но не был обработан)

//         // Здесь дочерний процесс будет в статусе зомби, так как родитель не вызвал wait()

//         printf("Теперь родитель вызывает wait(), чтобы удалить зомби процесс.\n");

//         // Вызов wait для получения статуса завершившегося дочернего процесса
//         int status;
//         if (wait(&status) < 0) {
//             perror("wait failed");
//             exit(1);
//         }

//         // Статус завершения дочернего процесса
//         if (WIFEXITED(status)) {
//             printf("Дочерний процесс завершился нормально с кодом: %d\n", WEXITSTATUS(status));
//         } else if (WIFSIGNALED(status)) {
//             printf("Дочерний процесс завершился сигналом: %d\n", WTERMSIG(status));
//         } else if (WIFSTOPPED(status)) {
//             printf("Дочерний процесс был остановлен сигналом: %d\n", WSTOPSIG(status));
//         }
//     }

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>

extern int etext, edata, end;  // Объявление переменных

int main() {
    printf("Address of etext: %p\n", (void*)&etext);
    printf("Address of edata: %p\n", (void*)&edata);
    printf("Address of end: %p\n", (void*)&end);

    return 0;
}