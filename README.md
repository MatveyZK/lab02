## Homework

### Part I

1. Создайте пустой репозиторий на сервисе github.com (или gitlab.com, или bitbucket.com).
2. Выполните инструкцию по созданию первого коммита на странице репозитория, созданного на предыдещем шаге.
```
$ git init
$ git remote add origin https://github.com/MatveyZK/lab02
$ git add .
$ git commit -m "Added README.md"
$ git push origin master
```
3. Создайте файл `hello_world.cpp` в локальной копии репозитория (который должен был появиться на шаге 2). Реализуйте программу **Hello world** на языке C++ используя плохой стиль кода. Например, после заголовочных файлов вставьте строку `using namespace std;`.
```
$ nano hello_world.cpp
```
4. Добавьте этот файл в локальную копию репозитория.
```
$ git add hello_world.cpp 
```
5. Закоммитьте изменения с *осмысленным* сообщением.
```
$ git commit -m "Added hello_world.cpp with bad code style"
```
6. Изменитьте исходный код так, чтобы программа через стандартный поток ввода запрашивалось имя пользователя. А в стандартный поток вывода печаталось сообщение `Hello world from @name`, где `@name` имя пользователя.
7. Закоммитьте новую версию программы. Почему не надо добавлять файл повторно `git add`?
Не нужно делать git add, так как стоит флаг -a
```
$ git commit -am "Added user name to hello_world.cpp"
```
8. Запуште изменения в удалёный репозиторий.
```
$ git push origin master
```
9. Проверьте, что история коммитов доступна в удалёный репозитории.

### Part II

**Note:** *Работать продолжайте с теми же репоззиториями, что и в первой части задания.*
1. В локальной копии репозитория создайте локальную ветку `patch1`.
```
$ git branch patch1
```
2. Внесите изменения в ветке `patch1` по исправлению кода и избавления от `using namespace std;`.
```
$ git checkout patch1
$ nano hello_world.cpp 
```
3. **commit**, **push** локальную ветку в удалённый репозиторий.
```
$ git commit -am "Deleted using namespace std"
$ git push origin patch1
```
4. Проверьте, что ветка `patch1` доступна в удалёный репозитории.
5. Создайте pull-request `patch1 -> master`.
6. В локальной копии в ветке `patch1` добавьте в исходный код комментарии.
```
$ nano hello_world.cpp 
```
7. **commit**, **push**.
```
$ git commit -am "Added comments"
$ git push origin patch1
```
8. Проверьте, что новые изменения есть в созданном на **шаге 5** pull-request
9. В удалённый репозитории выполните  слияние PR `patch1 -> master` и удалите ветку `patch1` в удаленном репозитории.
10. Локально выполните **pull**.
```
$ git checkout master
$ git pull
```
11. С помощью команды **git log** просмотрите историю в локальной версии ветки `master`.
```
$ git log
commit 9ef9cce48b6ba3e9b5c6468a26cada892076b551 (HEAD -> master, origin/master)
Merge: 4b5e12b 205d4da
Author: MatveyZK <zharkov.matvey@internet.ru>
Date:   Sun Mar 15 17:22:48 2026 +0300

    Merge pull request #1 from MatveyZK/patch1
    
    Deleted using namespace std

commit 205d4da0240847aefa93fcd93d9fcb04d9d8f8f9 (origin/patch1)
Author: MatveyZK <zharkov.matvey@internet.ru>
Date:   Sun Mar 15 14:20:16 2026 +0000

    Added comments

commit 62d739d23b0870bc2705057d3869badde65497ef
Author: MatveyZK <zharkov.matvey@internet.ru>
Date:   Sun Mar 15 14:14:43 2026 +0000

    Deleted using namespace std

commit 4b5e12be4bf86f5afec4574dafc3c1e3d0661ced
Author: MatveyZK <zharkov.matvey@internet.ru>
Date:   Sun Mar 15 14:00:01 2026 +0000

    Added user name to hello_world.cpp

commit 1e304624282d50d784ad7a82399a36b3b9d3a6ae
Author: MatveyZK <zharkov.matvey@internet.ru>
Date:   Sun Mar 15 13:51:22 2026 +0000

    Added hello_world.cpp with bad code style

commit 753cfaa8f67beed4314e4f97e57052e5a01b0234
Author: MatveyZK <zharkov.matvey@internet.ru>
Date:   Sun Mar 15 13:39:34 2026 +0000

    Added README.md
```
12. Удалите локальную ветку `patch1`.
```
$ git branch -D patch1
Deleted branch patch1 (was 205d4da).
```
### Part III

**Note:** *Работать продолжайте с теми же репоззиториями, что и в первой части задания.*
1. Создайте новую локальную ветку `patch2`.
```
$ git branch patch2
$ git checkout patch2
```
2. Измените *code style* с помощью утилиты [**clang-format**](http://clang.llvm.org/docs/ClangFormat.html). Например, используя опцию `-style=Mozilla`.
```
$ sudo apt install clang-format
$ clang-format -i -style=Mozilla hello_world.cpp
```
3. **commit**, **push**, создайте pull-request `patch2 -> master`.
```
$ git commit -am "Formated with clang"
$ git push origin patch2
```
4. В ветке **master** в удаленном репозитории измените комментарии, например, расставьте знаки препинания, переведите комментарии на другой язык.
5. Убедитесь, что в pull-request появились *конфликтны*.
6. Для этого локально выполните **pull** + **rebase** (точную последовательность команд, следует узнать самостоятельно). **Исправьте конфликты**.
```
$ git pull --rebase origin master
From https://github.com/MatveyZK/lab02
 * branch            master     -> FETCH_HEAD
Auto-merging hello_world.cpp
CONFLICT (content): Merge conflict in hello_world.cpp
error: could not apply 2d45571... Formated with clang
hint: Resolve all conflicts manually, mark them as resolved with
hint: "git add/rm <conflicted_files>", then run "git rebase --continue".
hint: You can instead skip this commit: run "git rebase --skip".
hint: To abort and get back to the state before "git rebase", run "git rebase --abort".
hint: Disable this message with "git config advice.mergeConflict false"
Could not apply 2d45571... Formated with clang
$ cat hello_world.cpp 
#include <iostream>
#include <string>

<<<<<<< HEAD
int main(){
	std::string name; //Comments
	std::cout<<"Your name: "; //Comments
	std::getline(cin, name); //Comments
	std::cout<<"Hello world from "<<name<<std::endl; //Comments
=======
int
main()
{
  std::string name;           // Комментарии
  std::cout << "Your name: "; // Комментарии
  std::getline(cin, name);    // Комментарии
  std::cout << "Hello world from " << name << std::endl; // Комментарии
>>>>>>> 2d45571 (Formated with clang)
}
$ nano hello_world.cpp 
$ cat hello_world.cpp 
#include <iostream>
#include <string>

int
main()
{
  std::string name;           // Comments
  std::cout << "Your name: "; // Comments
  std::getline(cin, name);    // Comments
  std::cout << "Hello world from " << name << std::endl; // Comments
}

$ git add hello_world.cpp 
$ git rebase --continue
[detached HEAD f8adff0] Formated with clang
 1 file changed, 7 insertions(+), 5 deletions(-)
Successfully rebased and updated refs/heads/patch2.
```
7. Сделайте *force push* в ветку `patch2`
```
$ git push --force origin patch2
```
8. Убедитель, что в pull-request пропали конфликтны. 
9. Вмержите pull-request `patch2 -> master`.




