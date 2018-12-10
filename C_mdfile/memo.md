개발자가 프로그램이 하는 업무를 먼저 익히는 것을 업무파악 이라한다.

문법은 명령을 정확하게 작성하는 기술

작문은 작성한 명령을 논리적으로 배치하는 기술이 필요

low level : 어셈블러
high level : 베이직 언어

c언어의 뿌리는 최초의 구조적 언어인 algol이다
b언어를 개량하여 c 언어를 만들었다.

algol60 -> bcpl -> b -> c -> c++

각 개발사들마다 컴파일러를 내놈으로서 이식성이 없어지고 이식성을 복구하기위해 표준이 필요하게 되었다

미 표준 위원회인 ansi는 83년부터 표준 제정 작업에 들어가 90년에 표준안을 완성 90년에 iso에 의해 승인 되었다.

ansi c는 클래식 c 에비해 안전성을 높이고 애매한 기능을 정리했으며 다음과 같은 기능을 추가

* 표준 라이브러리 함수를 규격화 했으며 헤더 파일도 통일
* 함수의 원형 선언 기능이 추가되어 컴파일러가 함수 호출부에서 타입 체크를 할 수 있다.
* 정수 실수 상수의 타입을 지정할 수 있는 L U F 등의 접미어가 추가되었다.
* enum void 형과 const volatile 제한자가 추가되었다. 
* 인접 문자열과 상수를 합쳐주고 확장열의 기능도 추가되었다.
* 함수 내부에서 선언하는 지역 배열이나 구조체를 초기화 할 수있다.

* 구조체 끼리 대입할 경우 구조체 크기만큼 메모리 복사를 한다.

이후에도 c 표준은 지속적으로 확장 95년에 유럽과 동양의 언어를 지원하기 윈한 멀티 바이트 문자 지원이 추가

이에 제정된 c 표준을 c95라 한다.

c++은 ANSI C 를 기준으로 하기 떄문에 그 이후에 c 문법에 대해서는 당분간 관심을 두지 않아도 될 듯하다.

C++은 C의 문법을 그대로 유지하면서 OOP(객체 지향 프로그래밍) 을 추가했다.

++은 증가 연산을 뜻하며 C에서 한단계 진화했다는 뜻을 가지고있다.

80년대 후반부터 소프트웨어가 하드웨어으이 발전을 따라잡지 못하는 소프트웨어 위기 문제가 대두

그 해결책으로 `OOP가 제시되었다.

당시 C++은 소프트웨어 위기의 해결사로 인식 90년대부터 본격적으로 사용되기 시작해서 지금의 대부분의 대형 프로젝트에 활용되었다.

C++은 C와 비교해서 클래스 상속 다형성 템플릿 등이 추가 되었다.

이외에 기존 c 언어로부터 물려받은 문법도 확장되었다

* 한줄 주석을 //로 표기가능

* 새로운 진위형인 bool타입이 추가

* 구조체나 열거형의 태그 이름을 하나의 타입으로 인정

* 함수 중간에서 변수를 선언가능

개인적으로 C++은 C의 상위버전이라 생각한다.

실제로 c 의 문법중 C+++ 이 지원하지 못하는 부분도 있는데 이런 문법은 대부분 안정성 이식성에 문제가 있거나 더 좋은 해결 방법이 있어 제외된 것들이다.

두언어의 개발 방법이 다르다는 주장은 실제로 사실이며 문제 해결을 위한 접근 방법 자체가 다르다.

그러나 C++은 객체 지향만 지원하는 것이 아니라 c의 구조적 개발방법도 여전히 지원하며 필요할 경우 c++로도 C스타일의 프로그램을 작성할 수 있다.

구조적 프로그래밍 방법이 객체 지향보다 열등하다고 생각하는 것도 일종의 고정 관념일 뿐이며 필료하다면 쓸수있다.

C++도 C와 마찬가지로 초창기에는 무분별한 기능 추가로 인해 호환성의 문제가 있었다.

90년대 초반의 볼랜드 C++과 비쥬얼 C++이 서로호환되지 않았던 것이 대표적 예이다.

C++의 첫 표준안인 iso 14992는 98년에 발표 되었다.

이표준안은 89년에 제정된 ansi c와 95년에 개정된 c95를 기반으로하며 C++의 객체 지향적인 기능을 추가하여 작성된 것이다.

그러나 1년 는은 99년에 새로 제정된 C99 표준을 포함하지는 못하며 그래서 14882는 C99와는 다르다.

c++을 쓰는것이 무조건적으로 옳다? 













































 