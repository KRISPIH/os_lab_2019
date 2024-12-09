### TCP и TCP/IP
**TCP (Transmission Control Protocol)** — протокол транспортного уровня в модели OSI, обеспечивающий надежную передачу данных между устройствами в сети. TCP гарантирует доставку данных в правильной последовательности и с минимальной потерей.

**TCP/IP** — это набор сетевых протоколов, основа для современных сетей, включая Интернет. Его основными компонентами являются:
- **IP (Internet Protocol)**: обеспечивает адресацию и маршрутизацию пакетов.
- **TCP**: предоставляет механизм надежной передачи данных.
- Другие протоколы: UDP, ICMP, HTTP, FTP и т.д.

---

### TCP vs UDP
| **Характеристика**     | **TCP**                                  | **UDP**                                  |
|-------------------------|------------------------------------------|------------------------------------------|
| Надежность             | Гарантирует доставку, контроль потерь   | Не гарантирует доставку                 |
| Установление соединения| Требуется (трехэтапное рукопожатие)     | Не требуется                            |
| Скорость передачи      | Медленнее из-за проверок                | Быстрее, минимальная задержка           |
| Использование          | Приложения с высокой надежностью (HTTP, FTP) | Стриминг, игры, VoIP                   |
| Контроль потока        | Есть                                     | Нет                                     |

---

### Системные вызовы в сетевом программировании

#### 1. **`socket`**
Создает сетевой сокет. 
```c
int socket(int domain, int type, int protocol);
```
- **`domain`**: определяет семейство протоколов (`AF_INET` для IPv4, `AF_INET6` для IPv6).
- **`type`**: тип сокета (`SOCK_STREAM` для TCP, `SOCK_DGRAM` для UDP).
- **`protocol`**: указывает конкретный протокол (обычно 0).

**Пример:**
```c
int sockfd = socket(AF_INET, SOCK_STREAM, 0);
```

#### 2. **`bind`**
Привязывает сокет к определенному адресу и порту.
```c
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
```
- **`sockfd`**: дескриптор сокета.
- **`addr`**: указатель на структуру с адресом (`struct sockaddr_in`).
- **`addrlen`**: размер структуры адреса.

**Пример:**
```c
struct sockaddr_in server_addr;
server_addr.sin_family = AF_INET;
server_addr.sin_addr.s_addr = INADDR_ANY;
server_addr.sin_port = htons(8080);

bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
```

#### 3. **`listen`**
Переводит сокет в режим ожидания входящих соединений.
```c
int listen(int sockfd, int backlog);
```
- **`sockfd`**: дескриптор сокета.
- **`backlog`**: максимальное число ожидающих соединений.

**Пример:**
```c
listen(sockfd, 5);
```

#### 4. **`accept`**
Принимает входящее соединение.
```c
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
```
- **`sockfd`**: дескриптор сокета.
- **`addr`**: указатель на структуру для хранения адреса клиента.
- **`addrlen`**: размер структуры адреса.

**Пример:**
```c
struct sockaddr_in client_addr;
socklen_t client_len = sizeof(client_addr);
int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
```

#### 5. **`recv`**
Получает данные из сокета.
```c
ssize_t recv(int sockfd, void *buf, size_t len, int flags);
```
- **`sockfd`**: дескриптор сокета.
- **`buf`**: буфер для хранения данных.
- **`len`**: размер буфера.
- **`flags`**: флаги для управления операцией.

**Пример:**
```c
char buffer[1024];
int n = recv(client_sockfd, buffer, sizeof(buffer), 0);
```

#### 6. **`send`**
Отправляет данные через сокет.
```c
ssize_t send(int sockfd, const void *buf, size_t len, int flags);
```
- **`sockfd`**: дескриптор сокета.
- **`buf`**: данные для отправки.
- **`len`**: размер данных.
- **`flags`**: флаги для управления операцией.

**Пример:**
```c
const char *message = "Hello, client!";
send(client_sockfd, message, strlen(message), 0);
```

#### 7. **`close`**
Закрывает сокет.
```c
int close(int sockfd);
```

**Пример:**
```c
close(client_sockfd);
```

#### 8. **`connect`**
Устанавливает соединение с удаленным сервером.
```c
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
```
- **`sockfd`**: дескриптор сокета.
- **`addr`**: структура с адресом сервера.
- **`addrlen`**: размер структуры адреса.

**Пример:**
```c
struct sockaddr_in server_addr;
server_addr.sin_family = AF_INET;
server_addr.sin_port = htons(8080);
inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
```

--- 

Эти вызовы позволяют создавать клиентские и серверные приложения, взаимодействующие через сеть.