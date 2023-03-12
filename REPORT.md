## Laboratory work II

Данная лабораторная работа посвещена изучению систем контроля версий на примере **Git**.

```bash
$ open https://git-scm.com
```

## Tasks

- [x] 1. Создать публичный репозиторий с названием **lab02** и с лиценцией **MIT**
- [x] 2. Сгенирировать токен для доступа к сервису **GitHub** с правами **repo**
- [x] 3. Ознакомиться со ссылками учебного материала
- [x] 4. Выполнить инструкцию учебного материала
- [x] 5. Составить отчет и отправить ссылку личным сообщением в **Slack**


## Homework

### Part I

1. Создайте пустой репозиторий на сервисе github.com (или gitlab.com, или bitbucket.com).

[**ссылка на репозиторий**](https://github.com/TheMatrix2/lab02)

2. Выполните инструкцию по созданию первого коммита на странице репозитория, созданного на предыдещем шаге.

`cd TheMatrix2/workspace/reports`
`git clone https://github.com/TheMatrix2/lab02 lab02`
`cd lab02`
`mkdir source`

3. Создайте файл `hello_world.cpp` в локальной копии репозитория (который должен был появиться на шаге 2). Реализуйте программу **Hello world** на языке C++ используя плохой стиль кода. Например, после заголовочных файлов вставьте строку `using namespace std;`.

`cat > sources/hello_world.cpp << EOF`
`>#include <iostream>`
`>using namespace std;`
`>`
`>int main(){`
`>cout << "Hello" << "world" << "!";`
`>}`
`>EOF`

4. Добавьте этот файл в локальную копию репозитория.

`git add .`

5. Закоммитьте изменения с *осмысленным* сообщением.

`git commit -m "added hello_world.cpp"`
`git push origin main`

6. Изменитьте исходный код так, чтобы программа через стандартный поток ввода запрашивалось имя пользователя. А в стандартный поток вывода печаталось сообщение `Hello world from @name`, где `@name` имя пользователя.

`nano edit sources/hello_world`

7. Закоммитьте новую версию программы. Почему не надо добавлять файл повторно `git add`?

`git add .`
`git commit -m "удаление добавления всего пространства имен std; добавление возможности ввода имени пользователя с последующим выводом сообщения"`

8. Запуште изменения в удалёный репозиторий.

`git push origin main`

9. Проверьте, что история коммитов доступна в удалёный репозитории.

### Part II

**Note:** *Работать продолжайте с теми же репоззиториями, что и в первой части задания.*
1. В локальной копии репозитория создайте локальную ветку `patch1`.

`git checkout -b patch1`

2. Внесите изменения в ветке `patch1` по исправлению кода и избавления от `using namespace std;`.

`nano edit sources/hello_world.cpp`
`git add .`

3. **commit**, **push** локальную ветку в удалённый репозиторий.

`git commit -m "создание ветки patch1; изменение файла hello_world.cpp в новой ветке"`
`git push origin patch1`

4. Проверьте, что ветка `patch1` доступна в удалёный репозитории.
5. Создайте pull-request `patch1 -> master`.
6. В локальной копии в ветке `patch1` добавьте в исходный код комментарии.
7. **commit**, **push**.
8. Проверьте, что новые изменения есть в созданном на **шаге 5** pull-request
9. В удалённый репозитории выполните  слияние PR `patch1 -> master` и удалите ветку `patch1` в удаленном репозитории.
10. Локально выполните **pull**.

`git pull`

11. С помощью команды **git log** просмотрите историю в локальной версии ветки `master`.

`git log`

12. Удалите локальную ветку `patch1`.

`git switch main`
`git branch -d patch1`


### Part III

**Note:** *Работать продолжайте с теми же репоззиториями, что и в первой части задания.*
1. Создайте новую локальную ветку `patch2`.

`git checkout -b patch2`

2. Измените *code style* с помощью утилиты [**clang-format**](http://clang.llvm.org/docs/ClangFormat.html). Например, используя опцию `-style=Mozilla`.

`clang-format -i -style=Mozilla sources/hello_world.cpp`

3. **commit**, **push**, создайте pull-request `patch2 -> master`.

`git add .`
`git commit -m "изменение code style в файле hello_world.cpp"`
`git push origin patch2`

4. В ветке **master** в удаленном репозитории измените комментарии, например, расставьте знаки препинания, переведите комментарии на другой язык.
5. Убедитесь, что в pull-request появились *конфликтны*.
6. Для этого локально выполните **pull** + **rebase** (точную последовательность команд, следует узнать самостоятельно). **Исправьте конфликты**.

`git pull`
`nano edit sources/hello_world.cpp`
`git add .`
`git commit -m "внесение исправлений в конфликтующий файл"`
`git rebase main`
`nano edit sources/hello_world.cpp`
`git add .`
`git rebase --continue`
`git pull origin main`
`git push -f origin patch2`

7. Сделайте *force push* в ветку `patch2`

`git push -f origin patch2`

8. Убедитеcь, что в pull-request пропали конфликтны. 
9. Вмержите pull-request `patch2 -> master`.

`git switch main`
`git merge patch2`

## Links

- [hub](https://hub.github.com/)
- [GitHub](https://github.com)
- [Bitbucket](https://bitbucket.org)
- [Gitlab](https://about.gitlab.com)
- [LearnGitBranching](http://learngitbranching.js.org/)

```
Copyright (c) 2015-2021 The ISC Authors
```
