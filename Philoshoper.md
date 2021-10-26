# Philoshoper

## Process && Thread

### 프로세스란

- '컴퓨터에서 연속적으로 실행되고 있는 프로그램'
- 메모리에 올라와 실행되고 있는 프로그램의 인스턴스(독립적 개체)
- 운영체제로부터 시스템 자원을 할당받는 작업의 단위

특징

- 프로세스는 각각 독립된 메모리 영역 (Code, Data, Stack, Heap 구조)을 할당받음
- 기본적으로 프로세스 당 최소 1개의 스레드 (메인 스레드)를 가지고 있다.
- 각 프로세스는 별도의 메모리 주소공간에서 실행되며, 한 프로세스는 다른 프로세스의 변수, 자료구조에 접근할 수 없음
- 한 프로세스가 다른 프로세스에 접근하려면, 프로세스간 통신 (IPC, Inter-Process Communication)을 사용해야 한다.

### 스레드란

- 프로세스 내에서 실행되는 여러 실행 흐름의 단위
- 프로세스의 특정한 수행 경로
- 프로세스가 할당받은 자원을 이용하는 실행 단위

특징

- 스레드는 프로세스 내에서 각각 `Stack만 할당받고, Code, Data, Heap 영역은 공유`
- 스레드는 한 프로세스 내에서 동작되는 여러 실행의 흐름으로, 프로세스 내의 공간, 자원을 같은 프로세스 내에 스레드끼리 공유하면서 실행
- 같은 프로세스 안에 있는 여러 스레드들은 같은 힙 공간을 공유
- 각각의 스레드는 별도의 레지스터와 스택을 갖고있음
- 한 스레드가 프로세스 자원을 변경하면, 다른 스레드도 그 변경결과를 즉시 확인 가능



## Deadrock(교착상태)

두개 이상의 프로세스가 서로의 작업이 끝나기만을 기다리고 있어 둘 다 영원히 끝나지 않는 상황

### 필요조건

4가지 조건이 모두 만족하면 교착상태 발생 가능성이 있음

하나라도 만족하지 않으면, 절대 발생하지 않음

1. 상호 배제 (Mutual exclusion) - mutex

   한 리소스는 한번에 한 프로세스만 사용할 수 있음

   **Mutex**: 스레드의 러닝타임이 서로 겹치지 않게, 단독으로 실행되게하는 기술

   Locking mechanism 으로 오직 하나의 스레드만이 동일한 시점에 뮤텍스를 얻어 임계영역 (Critical Section)에 들어올 수 있고, 이 스레드 만이 임계영역에서 나갈 때 뮤텍스를 해제할 수 있음.

   **임계영역** : 하나의 한 스레드 만이 진입해야하는 특정 코드 구역

2. 점유와 대기 (Hold & wait)

   어떤 프로세스가 하나 이상의 리소스를 점유하고 있으면서, 다른 프로세스가 가지고 있는 리소스를 기다리고 있음

3. 비선점 (No preeption)

   프로세스가 task를 마친 후, 리소스를 자발적으로 반환할 때까지 기다림

4. 환형 대기 (Circular wait)

   Hold & wait 관계의 프로세스들이 서로를 기다림

### 방지법

1. 방지

   할당 구조 측면에서, 교착상태가 발생할 수 있는 요구조건을 만족시키지 않게 함으로써 교착상태를 방지

2. 회피

   리소스 할당 측면에서, 교착상태가 발생할 수 있는 요구조건을 만족시키지 않게 함으로써 교착상태를 방지

3. 탐지 및 회복

   교착상태가 발생할 수 있도록 놔두고, 교착상태가 발생할 경우 찾아내어 고침

## Mandatory

- C로 작성, Norm 지킴, 누수, 충돌 등 금지
- 하나 혹은 다수의 철학자는 원형 테이블에 앉아서 3가지 행동 중 하나를 시행 : 먹기, 생각하기, 자기
- 하나의 행동을 하는 동안, 다른 두 가지 행동을 할 수 없음
- 철학자들이 앉아있는 원형테이블 위에는 중앙에 큰 그릇에 파스타가 위치함
- 파스타는 하나의 포크로는 먹을 수 없어서, 철학자들은 양 손에 포크를 들고 먹어야 함
- 철학자들은 절대 굶주려선 안됨, 모든  철학자들은 밥을 먹어야 함
- 철학자들은 서로 이야기할 수 없고, 다/른 철학자가 죽었을 때 알 수 없다
- 철학자가 식사를 끝내는 매 시간마다 포크를 내려놓고 잠을 잠
- 철학자가 잠을 다 자면, 생각을 시작
- 철학자가 죽으면, 시뮬레이션을 멈춤

- 각 프로그램은 같은 옵션을 갖는다.
  - Number_of_philosophers : 철학자의 수와 포크의 수
  - time_to_die : ms 단위, 철학자가 지난번 식사 후 time_to_die 내에 식사를 시작하지않으면 철학자는 죽음
  - time_to_eat : 철학자가 밥을 먹는 데에 걸리는 시간
  - time_to_sleep : 철학자가 잠을 자는 데에 보내는 시간
  - Number_of_times_each_philosopher_must_eat : 선택적 인자로서 모든 철학자의 식사횟수가 해당 옵션에 도달하면 시뮬레이션 중단. 옵션이 정해지지 않은 경우 시뮬레이션은 철학자가 죽는 시간에 종료
- 모든 철학자는 1 ~ number_of_philosophers 까의 숫자를 부여받음
- Philosopher number 1 은 number_of_philosophers 옆에 있어야함, 즉 N번째 철학자는 N-1번째 철학자와 N+1번째 철학자 사이에 있어야한다.
- 철학자의 상태변화는 (X = philosopher number, timestamp_in_ms = ms로 표현된 timestamp)
  - Timestamp_in_ms X has taken a fork
  - Timestamp_in_ms X is eating
  - Timestamp_in_ms X is sleeping
  - Timestamp_in_ms X is thinking
  - Timestamp_in_ms X died
- 어떤 철학자의 상태가 출력되는 것은 다른 철학자의 상태가 출력되는 것과 섞이면 안된다.
- 어떤 철학자의 죽음은 그 철학자의 상태 출력까지 10ms 이상 걸리면 안된다.

### philo

- 각 철학자 양 옆으로 포크가 존재
- 포크들이 복제되는 것을 막기위해, mutex(상호배제)를 통해 포크의 상태를 보호해야함
- 철학자는 스레드여야함

### philo_Bonus

- 모든 포크는 테이블 가운데에 위치
- 포크의 상태는 메모리에 저장되어있지 않지만, 사용가능한 포크는 semaphore에서 확인
- 각각의 철학자는 하나의 프로세이고, 메인 프로세스는 철학자가 아니다.

## 허용함수

### gettimeofday

```c
gettimeofday(struct timeval *tv, struct timezone *tz)

struct timeval{ // 시간을 저장할 버퍼
  time_t	tv_sec; //초가 저장
  suseconds_t	tv_usec; //ms가 저장
}

struct timezone { //값은 무시, NULL사용, timezone은 사용하지 않음
  int	tz_minuteswest;
  int	tz_dsttime;
}
```

1970-01-01 00:00:00 이후 현재까지의 경과된 초와 micro초 값을 얻는 함수

성공 시 1 반환

### pthread_create

```c
int pthread_create (pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg)
```

쓰레드 생성

- 첫번째 매개변수 thread는 스레드가 성공적으로 생성되었을 때, 생성된 쓰레드를 식별하기 위해서 사용되는 쓰레드 식별자
- 두번째 매개변수 attr는 스레드 특성을 지정하기 위해 사용하며, 기본 스레드 특성을 사용할 경우 NULL 사용
  - 세번째 매개변수 start_routine은 분기시켜서 실행할 스레드 함수
- 네번째 매개변수 arg는 위 start_routine 스레드 함수의 매개변수로 넘겨짐

성공 시 0, 실패 시 에러코드 리턴 

### pthread_detach

```c
int	pthread_detach(pthread_t th)
```

특정 스레드를 분리시킴

일반적으로 pthread_create를 사용하여 새로운 스레드를 생성하면, 스레드가 종료되더라도 사용했던 모든 자원이 해제되지않음

pthread_join을 사용하여 종료될 때까지 기다렸다가 종료시점이 되면, 자원을 반납

-> pthread_detach는 **pthread_join()을 사용하지 않더라도, 스레드가 종료될 때 모든 자원을 해제**

- 첫번째 매개변수 th 는 분리시킬 스레드 식별자

성공 시 0, 실패 시 에러코드 리턴

### pthread_join

```c
int	pthread_join (pthread_t th, void **thread_return)
```

특정 스레드가 종료하기를 기다렸다가, 스레드가 종료된 이후 다음 진행

join된 스레드(종료된 스레드)는 모든 자원을 반납

- 첫번째 매개변수 th는 기다릴 스레드 식별자
- 두번째 매개변수 thread_return 은 스레드의 리턴값
  - Thread_return 이 NULL이 아닌 경우, 해당 포인터로 스레드의 리턴 값을 받아올 수 있음

성공시  0, 실패 시 에러코드 리턴

### pthread_mutex_init

```c
int	pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr)
```

mutex를 초기화

- 첫번째 인자는 mutex
- 두번째 인자는 mutex의 속성을 주는데 기본적으로 NULL 사용

성공 시 0, 실패시 에러코드 리턴

### pthread_mutex_destroy

```c
int	pthread_mutex_destroy(pthread_mutex_t *mutex)
```

pthread_mutex_init으로 mutex를 위해 할당되었던 리소스를 해제

- 첫번째 인자는 mutex

성공 시 0, 실패시 에러코드 리턴

### pthread_mutex_lock

```c
int	pthread_mutex_lock(pthread_mutex_t *mutex)	
```

생성된 mutex를 잠금

- 첫번째 인자는 mutex

성공 시 0, 실패 시 에러코드 리턴

### pthread_mutex_unlock

```c
int	pthread_mutex_unlock(pthread_mutex_t *mutex)	
```

잠겨있는 mutex를 해제

- 첫번째 인자는 mutex

성공 시 0, 실패 시 에러코드 리턴 
