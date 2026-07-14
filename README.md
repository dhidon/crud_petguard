# CRUD PET_GUARD
PetGuard é um projeto em desenvolvimento voltado para o cuidado colaborativo de animais de rua.
Este código faz parte da ideia inicial de persistência dos dados da aplicação, que seriam salvas em um binário por meio da linguagem C.
A linguagem C foi escolhida inicialmente para praticar e também pela sua eficiência, porém a aplicação necessitava de um banco de dados relacional mais robusto.
---
# Forma de operação
Ao salvar um usuário ou animal novo, o ID da vez é verificado no arquivo correspondente dentro de `\configs`. Após pegar o ID, os dados são montados e salvos no arquivo binário correspondente dentro de `\data`.
## Rodando o código
Antes de mais nada é importante clonar o repositório para a sua máquina com `git clone {endereço}`
Depois rode o código com o comando `make`.
# Comandos
Os comandos básicos desse código devem ser iniciados com `main` seguidos do comando e os dados necessários.
## Listar animais
```
./main --animais
```
## Listar usuários
```
./main --usuarios
```
## Adicionar animal
Esse comando deve ser seguido dos dados a serem inseridos:
- Nome;
- Status\*;
- Tipo\*;
- Raça\*;
- Cor\*;
- Tamanho\*;
- Idade;
- Cuidador\*\*;
- Latitude;
- Logitude;
- Data;
- Sexo\*;
```
./main --salvar-animal {dados}
```
## Mostrar animal específico
```
./main --listar-animal {id}
```
## Edital animal
```
./main --editar-animal {id, dados}
```
## Deletar animal
```
./main --deletar-animal {id}
```
## Adicionar usuário
Esse comando deve ser seguido dos dados:
- Nome;
- Tipo*;
- Telefone;
- E-mail;
- Data;
```
./main --salvar-user {dados}
```
## Editar usuário
```
./main --editar-user {id, dados}
```
## Deletar usuário
```
./main --deletar-user {id}
```
---
\* numeração de acordo com o enum em `\include\modelos.h`
\*\* ID do cuidador responsável.
