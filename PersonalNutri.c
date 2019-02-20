#include<stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
struct tipoDieta{
	struct tipoCafe{
		char nomeAlimento[30];		
		float kcalAlimento;
		int exist;
	}alimentoCafe[100];
	struct tipoAlmoco{
		char nomeAlimento[30];		
		float kcalAlimento;
		int exist;
	}alimentoAlmoco[100];
	struct tipoJantar{
		char nomeAlimento[30];		
		float kcalAlimento;
		int exist;
	}alimentoJantar[100];
	float totalKcal;
	float kcalCafe;
	float kcalAlmoco;
	float kcalJantar;
	char preparoCafe[100];
	char preparoAlmoco[100];
	char preparoJantar[100];
}dietaPessoa[100];
struct tipoUsuario{
	char email[30];
	char senha[20];
	char nome[20];
	float peso;
	float altura;
	int config;
	int exist;
	int associacao;
}usuario[100];
struct tipoNutri{
	char email[30];
	char senha[20];
	char nome[20];
	int crm;	
	int configNutri;
	int cod;
	int existNutri;
}nutricionista[100];

struct tipoAlimento{
	char nomeAlimento[30];
	float kcalAlimento;
	int exist;
}alimento[100];

void home();
int verificarLogin(char email[],char senha[]);
void FuncCadastro();
int buscapaciente();
void app();
int ListarDieta(int auth);
int acaoN[15];
int acaoNNC[15];


main(){
	setlocale(LC_ALL, "Portuguese");
	/*AJUSTES*/
		int i,j;
		for(i=0;i<100;i++){
			usuario[i].associacao=-2;
			nutricionista[i].cod=-1;
			usuario[i].exist=0;
			nutricionista[i].existNutri=0;
			nutricionista[i].configNutri=-10;
			alimento[i].exist=0;
			usuario[i].config=-1;
			for(j=0;j<100;j++){
				dietaPessoa[i].alimentoCafe[j].exist=0;
				dietaPessoa[i].alimentoAlmoco[j].exist=0;
				dietaPessoa[i].alimentoJantar[j].exist=0;
			}
			
		}
	/*FIM: AJUSTES*/
	/* PRÉ-CADASTRO */
		/* INICIO: ALIMENTOS */
			char pao[]="Pão";
			strcpy(alimento[0].nomeAlimento, pao);
			alimento[0].kcalAlimento=265;
			alimento[0].exist=1;
			char ovo[]={"Ovo"};
			strcpy(alimento[1].nomeAlimento, ovo);
			alimento[1].kcalAlimento=155;
			alimento[1].exist=1;
			char arroz[]="Arroz";
			strcpy(alimento[2].nomeAlimento, arroz);
			alimento[2].kcalAlimento=130;
			alimento[2].exist=1;
			char feijaoPreto[]="Feijão Preto";
			strcpy(alimento[3].nomeAlimento,feijaoPreto);
			alimento[3].kcalAlimento=130;
			alimento[3].exist=1;
		/* FIM: ALIMENTOS */
		/* INICIO: PACIENTE */
			char emailcadastrado[30]={"joao@gmail.com"}, senhacadastrada[6]={"12345"},username[20]={"João"};
			strcpy(usuario[0].email,emailcadastrado);
			strcpy(usuario[0].senha,senhacadastrada);
			strcpy(usuario[0].nome,username);
			usuario[0].config=2;
			usuario[0].exist=1;
			usuario[0].associacao=0;
			usuario[0].altura=1.87;
			usuario[0].peso=83.9;
			strcpy(dietaPessoa[0].alimentoCafe[0].nomeAlimento,alimento[0].nomeAlimento);
			strcpy(dietaPessoa[0].alimentoCafe[1].nomeAlimento,alimento[1].nomeAlimento);
			strcpy(dietaPessoa[0].alimentoAlmoco[0].nomeAlimento,alimento[2].nomeAlimento);
			strcpy(dietaPessoa[0].alimentoAlmoco[1].nomeAlimento,alimento[3].nomeAlimento);
			strcpy(dietaPessoa[0].alimentoJantar[0].nomeAlimento,alimento[2].nomeAlimento);
			strcpy(dietaPessoa[0].alimentoJantar[1].nomeAlimento,alimento[3].nomeAlimento);
			dietaPessoa[0].alimentoCafe[0].exist=1;
			dietaPessoa[0].alimentoCafe[1].exist=1;
			dietaPessoa[0].alimentoAlmoco[0].exist=1;
			dietaPessoa[0].alimentoAlmoco[1].exist=1;
			dietaPessoa[0].alimentoJantar[0].exist=1;
			dietaPessoa[0].alimentoJantar[1].exist=1;
			dietaPessoa[0].alimentoCafe[0].kcalAlimento=265;
			dietaPessoa[0].alimentoCafe[1].kcalAlimento=155;
			dietaPessoa[0].alimentoAlmoco[0].kcalAlimento=130;
			dietaPessoa[0].alimentoAlmoco[1].kcalAlimento=130;
			dietaPessoa[0].alimentoJantar[0].kcalAlimento=130;
			dietaPessoa[0].alimentoJantar[1].kcalAlimento=130;
			dietaPessoa[0].kcalCafe=420;
			dietaPessoa[0].kcalAlmoco=260;
			dietaPessoa[0].kcalJantar=260;			
			dietaPessoa[0].totalKcal=dietaPessoa[0].kcalCafe+dietaPessoa[0].kcalAlmoco+dietaPessoa[0].kcalJantar;
			strcpy(dietaPessoa[0].preparoCafe,"Pão integral, cortado e servido com o ovo frito, sal a gosto.");
			strcpy(dietaPessoa[0].preparoAlmoco,"Arroz integral, cozido e servido com feijão preto, tempero a gosto.");
			strcpy(dietaPessoa[0].preparoJantar,"Arroz integral, cozido e servido com feijão preto, tempero a gosto.");
		/* FIM: PACIENTE */
		/* INICIO: NUTRICIONISTA */
			char emailCadN[30]={"claudio"}, senhaCadN[6]={"54321"},usernameCadN[20]={"Cláudio"};
			strcpy(nutricionista[0].email,emailCadN);
			strcpy(nutricionista[0].senha,senhaCadN);
			strcpy(nutricionista[0].nome,usernameCadN);
			nutricionista[0].configNutri=1;
			nutricionista[0].cod=0;
			nutricionista[0].existNutri=1;
			// AÇÕES DO NUTRICIONISTA:
				int acaoN[15],acaoNNC[15],acCont=0,acContN=0;		
		/* FIM: NUTRICIONISTA */
	/* FIM: PRÉ-CADASTRO */
			
	int auth=0,voltar=1,busca=0,cont=1,editDieta,a=0;
	char tentativaSenha[30],tentativaEmail[30],ConfirmarEdicao,tentativaAlimento[30];
		
	/*AÇÕES:*/	int classe,refeicao,cadastro;
	
// ------------------- INICIO DO ALGORITIMO ------------------- //
	while(voltar!=0){
		home();
		scanf("%d", &classe);
		fflush(stdin);
		switch(classe){
			case 1:// INICIO DO CASO: PACIENTE
				FuncCadastro();
				scanf("%d",&cadastro);
				fflush(stdin);
				switch(cadastro){
					case 1:// INICIO DO CASO: PACIENTE - JÁ POSSUI CADASTRO 
						while(voltar!=0){
							system("CLS");	
							printf(
								"+--------------------+\n"
								"¦    Tela de login   ¦\n"
								"+--------------------+\n"
							);
							printf("Insira seu e-mail: ");
							gets(tentativaEmail);
							printf("Insira sua senha: ");
							gets(tentativaSenha);
							auth=verificarLogin(tentativaEmail,tentativaSenha);
							if(auth==-1){
								printf("E-mail ou senha incorretos.\n");
								system("PAUSE");			
							}
							else{
								voltar=0;
							}
						}
						voltar=1;
						if(usuario[auth].config==1 || usuario[auth].config==0){
							while(voltar!=0){
								system("CLS");
								printf(".--------------------------------------,\n");
								printf("| .-----------------------------------, |\n");
								printf("| |                                   | |\n");
								printf("| |          (         Menu do        | |\n");
								printf("| |           )             Usuário   | |\n");
								printf("| |      __..---..__                  | |\n");
								printf("| |  ,-='  /  |  \\  `=-.              | |\n");
								printf("| | :--..___________..--;             | |\n");
								printf("| |  \\.,_____________,./              | |\n");
								printf("| |                                   | |\n");
								printf("| |___________________________________| |\n");
								printf("| |                                   | |\n");
								printf("| |     Aguardando nutricionista..    | |\n");
								printf("| |    Tente novamente mais tarde..   | |\n");
								printf("| |         Aperte 0 para sair.       | |\n");
								printf("| |___________________________________| |\n");
								printf("| |                                   | |\n");
								printf("| `-----------------------------------' |\n");
								printf("|                                       |\n");
								printf("`---------------------------------------'\n");
								scanf("%d",&voltar);
							}
							voltar=1;
						}
						else if(usuario[auth].config==2){
							system("CLS");
							printf("Olá %s! Vamos retomar seu acompanhamento.\n", usuario[auth].nome);
							printf("Sua meta diária é %.2f Kcal\n",dietaPessoa[auth].totalKcal);
							system("PAUSE");
							while(voltar!=0){
								system("CLS");
								printf(".--------------------------------------,\n");
								printf("| .-----------------------------------, |\n");
								printf("| |                                   | |\n");
								printf("| |                                   | |\n");
								printf("| |          (         Menu do        | |\n");
								printf("| |           )             Usuário   | |\n");
								printf("| |      __..---..__                  | |\n");
								printf("| |  ,-='  /  |  \\  `=-.              | |\n");
								printf("| | :--..___________..--;             | |\n");
								printf("| |  \\.,_____________,./              | |\n");
								printf("| |                                   | |\n");
								printf("| |___________________________________| |\n");
								printf("| |    ___________________            | |\n");
								printf("| |   |                   |           | |\n");
								printf("| |   |      Mostrar      | digite 1  | |\n");
								printf("| |   |   Café da Manhã   |           | |\n");
								printf("| |   |___________________|           | |\n");
								printf("| |                                   | |\n");
								printf("| |                                   | |\n");
								printf("| |    ___________________            | |\n");
								printf("| |   |                   |           | |\n");
								printf("| |   |      Mostrar      | digite 2  | |\n");
								printf("| |   |      Almoço       |           | |\n");
								printf("| |   |___________________|           | |\n");
								printf("| |                                   | |\n");
								printf("| |                                   | |\n");
								printf("| |    ___________________            | |\n");
								printf("| |   |                   |           | |\n");
								printf("| |   |      Mostrar      | digite 3  | |\n");
								printf("| |   |       Jantar      |           | |\n");
								printf("| |   |___________________|           | |\n");
								printf("| |                                   | |\n");
								printf("| |                                   | |\n");
								printf("| |    ___________________            | |\n");
								printf("| |   |                   |           | |\n");
								printf("| |   |       Sair        | Digite 0  | |\n");
								printf("| |   |___________________|           | |\n");
								printf("| |                                   | |\n");
								printf("| `-----------------------------------' |\n");
								printf("|                                       |\n");
								printf("`---------------------------------------'\n");
								scanf("%d",&refeicao);
								fflush(stdin);
								switch(refeicao){
									case 1://Inicio do caso: Usuario cadastrado - Mostrar café da manhã.
										while(voltar!=0){
											system("CLS");
											printf(".--------------------------------------,\n");
											printf("| .-----------------------------------, |\n");
											printf("| |                                   | |\n");
											printf("| |          (         Menu do        | |\n");
											printf("| |           )             Usuário   | |\n");
											printf("| |      __..---..__                  | |\n");
											printf("| |  ,-='  /  |  \\  `=-.              | |\n");
											printf("| | :--..___________..--;             | |\n");
											printf("| |  \\.,_____________,./              | |\n");
											printf("| |                                   | |\n");
											printf("| |       Pressione 0 para voltar     | |\n");
											printf("| |___________________________________| |\n");
											printf("| |                                   | |\n");
											printf("| |        ___________________        | |\n");
											printf("| |       |                   |       | |\n");
											printf("| |       |   Cafe da manhã:  |       | |\n");
											printf("| |       |___________________|       | |\n");
											printf("| |                                   | |\n");
											printf("| `-----------------------------------' |\n");
											printf("|                                       |\n");
											printf("`---------------------------------------'\n");
											printf(
												"+--------------------+\n"
												"¦      ALIMENTOS     ¦\n"
												"+--------------------+\n"
											);
											for(i=0;i<100;i++){
												if(dietaPessoa[auth].alimentoCafe[i].exist==1){
													printf(" %s - %.2f Kcal",dietaPessoa[auth].alimentoCafe[i].nomeAlimento,dietaPessoa[auth].alimentoCafe[i].kcalAlimento);															
													printf("\n");
												}
											}
											printf("\n");
											printf(
												"+--------------------+\n"
												"¦       PREPARO      ¦\n"
												"+--------------------+\n"
											);
											printf(" %s",dietaPessoa[auth].preparoCafe);
											printf("\n\n+--------------------+");
											printf("\nPara voltar digite 0: ");
											scanf("%d",&voltar);
											fflush(stdin);
										}
										voltar=1;
									break;//Fim do caso: Usuario cadastrado - Mostrar café da manhã.
									case 2://Inicio do caso: Usuario cadastrado - Mostrar almoço.
										while(voltar!=0){
											system("CLS");
											printf(".--------------------------------------,\n");
											printf("| .-----------------------------------, |\n");
											printf("| |                                   | |\n");
											printf("| |          (         Menu do        | |\n");
											printf("| |           )             Usuário   | |\n");
											printf("| |      __..---..__                  | |\n");
											printf("| |  ,-='  /  |  \\  `=-.              | |\n");
											printf("| | :--..___________..--;             | |\n");
											printf("| |  \\.,_____________,./              | |\n");
											printf("| |                                   | |\n");
											printf("| |       Pressione 0 para voltar     | |\n");
											printf("| |___________________________________| |\n");
											printf("| |                                   | |\n");
											printf("| |        ___________________        | |\n");
											printf("| |       |                   |       | |\n");
											printf("| |       |      Almoço:      |       | |\n");
											printf("| |       |___________________|       | |\n");
											printf("| |                                   | |\n");
											printf("| `-----------------------------------' |\n");
											printf("|                                       |\n");
											printf("`---------------------------------------'\n");
											printf(
												"+--------------------+\n"
												"¦      ALIMENTOS     ¦\n"
												"+--------------------+\n"
											);
											for(i=0;i<100;i++){
												if(dietaPessoa[auth].alimentoAlmoco[i].exist==1){
													printf(" %s - %.2f Kcal",dietaPessoa[auth].alimentoAlmoco[i].nomeAlimento,dietaPessoa[auth].alimentoAlmoco[i].kcalAlimento);															
													printf("\n");
												}
											}
											printf("\n");
											printf(
												"+--------------------+\n"
												"¦       PREPARO      ¦\n"
												"+--------------------+\n"
											);
											printf(" %s",dietaPessoa[auth].preparoAlmoco);
											printf("\n\n+--------------------+");
											printf("\nPara voltar digite 0: ");
											scanf("%d",&voltar);
											fflush(stdin);
										}
										voltar=1;
									break;//Fim do caso: Usuario cadastrado - Mostrar almoço.
									case 3://Inicio do caso: Usuario cadastrado - Mostrar jantar.
										while(voltar!=0){											
											system("CLS");
											printf(".--------------------------------------,\n");
											printf("| .-----------------------------------, |\n");
											printf("| |                                   | |\n");
											printf("| |          (         Menu do        | |\n");
											printf("| |           )             Usuário   | |\n");
											printf("| |      __..---..__                  | |\n");
											printf("| |  ,-='  /  |  \\  `=-.              | |\n");
											printf("| | :--..___________..--;             | |\n");
											printf("| |  \\.,_____________,./              | |\n");
											printf("| |                                   | |\n");
											printf("| |       Pressione 0 para voltar     | |\n");
											printf("| |___________________________________| |\n");
											printf("| |                                   | |\n");
											printf("| |        ___________________        | |\n");
											printf("| |       |                   |       | |\n");
											printf("| |       |      Jantar:      |       | |\n");
											printf("| |       |___________________|       | |\n");
											printf("| |                                   | |\n");
											printf("| `-----------------------------------' |\n");
											printf("|                                       |\n");
											printf("`---------------------------------------'\n");
											printf(
												"+--------------------+\n"
												"¦      ALIMENTOS     ¦\n"
												"+--------------------+\n"
											);
											for(i=0;i<100;i++){
												if(dietaPessoa[auth].alimentoJantar[i].exist==1){
													printf(" %s - %.2f Kcal",dietaPessoa[auth].alimentoJantar[i].nomeAlimento,dietaPessoa[auth].alimentoJantar[i].kcalAlimento);															
													printf("\n");
												}
											}
											printf("\n");
											printf(
												"+--------------------+\n"
												"¦       PREPARO      ¦\n"
												"+--------------------+\n"
											);
											printf(" %s",dietaPessoa[auth].preparoJantar);
											printf("\n\n+--------------------+");
											printf("\nPara voltar digite 0: ");
											scanf("%d",&voltar);
											fflush(stdin);
										}
										voltar=1;
									break;//Fim do caso: Usuario cadastrado - Mostrar jantar.
									case 0://Inicio do caso: Usuario cadastrado - Sair.
										voltar=0;
									break;//Fim do caso: Usuario cadastrado - Sair.
									default:
										voltar=1;
									break;
								}
							}
							voltar=1;
							auth=-1;
						}//CHAVE DA CONDICIONAL QUE PERGUNTA SE O USUARIO JÁ FOI CONFIG PELO NUTRI
					break;// FIM DO CASO: PACIENTE - JÁ POSSUI CADASTRO 
					case 2:// INICIO DO CASO: PACIENTE - NÃO POSSUI CADASTRO
						system("CLS");
						printf(
	    					"+--------------------+\n"
	    					"¦  Tela de cadastro  ¦\n"
	    					"+--------------------+\n"
						);
						printf("Vamos iniciar seu cadastro:\n");
						for(i=0;i<100;i++){
							if(usuario[i].exist==0){
								printf("Insira seu nome: ");
								scanf("%s",&usuario[i].nome);
								printf("Insira seu e-mail: ");
								scanf("%s", &usuario[i].email);
								printf("Insira sua senha: ");
								scanf("%s", &usuario[i].senha);
								system("CLS");
								printf(
			    					"+----------------------------+\n"
			    					"¦  Configurações adicionais  ¦\n"
			    					"+----------------------------+\n"
								);
								printf("Insira seu peso: ");
								scanf("%f",&usuario[i].peso);
								getchar();
								printf("Insira sua altura: ");
								scanf("%f",&usuario[i].altura);
								usuario[i].exist=1;
								usuario[i].config=0;
								i=100;
							}
						}
						printf("Conta criada com sucesso!\n");
						getchar();
						system("PAUSE");
						voltar=1;
					break;// FIM DO CASO: PACIENTE - NÃO POSSUI CADASTRO
					default:
						voltar=1;
					break; 
				}//Chave do switch cadastro DO PACIENTE.			
			break;// FIM DO CASO: PACIENTE
			case 2:// INICIO DO CASO: NUTRICIONISTA
				FuncCadastro();
				scanf("%d",&cadastro);
				fflush(stdin);
				switch(cadastro){
					case 1:// INICIO DO CASO: NUTRICIONISTA - POSSUI CADASTRO 
						while(voltar!=0){
							system("CLS");	
							printf(
								"+--------------------+\n"
								"¦    Tela de login   ¦\n"
								"+--------------------+\n"
							);
							printf("Insira seu e-mail: ");
							gets(tentativaEmail);
							printf("Insira sua senha: ");
							gets(tentativaSenha);
							auth=verificarLogin(tentativaEmail,tentativaSenha);
							if(auth==-1){
								printf("E-mail ou senha incorretos.\n");
								system("PAUSE");
								voltar=1;			
							}
							else{
								voltar=0;
							}
						}
						voltar=1;
						if(nutricionista[auth].configNutri==0 && nutricionista[auth].existNutri==1){
							while(voltar!=0){
								system("CLS");
								printf(".--------------------------------------,\n");
								printf("| .-----------------------------------, |\n");
								printf("| |                                   | |\n");
								printf("| |          (        Olá             | |\n");
								printf("| |           )        Nutricionista! | |\n");
								printf("| |      __..---..__                  | |\n");
								printf("| |  ,-='  /  |  \\  `=-.              | |\n");
								printf("| | :--..___________..--;             | |\n");
								printf("| |  \\.,_____________,./              | |\n");
								printf("| |                                   | |\n");
								printf("| |___________________________________| |\n");
								printf("| |                                   | |\n");
								printf("| |   _____________________           | |\n");
								printf("| |  |                     |          | |\n");
								printf("| |  |   Buscar paciente   | digite 1 | |\n");
								printf("| |  |_____________________|          | |\n");
								printf("| |                                   | |\n");
								printf("| |                                   | |\n");
								printf("| |                                   | |\n");
								printf("| |                                   | |\n");
								printf("| |                                   | |\n");
								printf("| |                                   | |\n");
								printf("| |                                   | |\n");
								printf("| |                                   | |\n");
								printf("| |                                   | |\n");
								printf("| |                                   | |\n");
								printf("| |                                   | |\n");
								printf("| |                                   | |\n");
								printf("| |    ___________________            | |\n");
								printf("| |   |                   |           | |\n");
								printf("| |   |       Sair        | Digite 0  | |\n");
								printf("| |   |___________________|           | |\n");
								printf("| |                                   | |\n");
								printf("| |                                   | |\n");
								printf("| `-----------------------------------' |\n");
								printf("|                                       |\n");
								printf("`---------------------------------------'\n");
								scanf("%d",&acaoN[0]);
								fflush(stdin);
								switch(acaoN[0]){
									case 1:
											busca=buscapaciente(auth);
											if(busca==-1){
												voltar=1;
											}
											else{												
												voltar=0;
											}
									break;
									case 0:
										voltar=0;
									break;
									default:
										voltar=1;
									break;
								}
							}
							voltar=1;
						}//fim da condicionar - nutri tem paciente?
						if(nutricionista[auth].configNutri==0){
							voltar=0;
						}
						while(voltar!=0){
							system("CLS");
							printf(".--------------------------------------,\n");
							printf("| .-----------------------------------, |\n");
							printf("| |                                   | |\n");
							printf("| |          (        Perfil:         | |\n");
							printf("| |           )        Nutricionista! | |\n");
							printf("| |      __..---..__                  | |\n");
							printf("| |  ,-='  /  |  \\  `=-.              | |\n");
							printf("| | :--..___________..--;             | |\n");
							printf("| |  \\.,_____________,./              | |\n");
							printf("| |                                   | |\n");
							printf("| |___________________________________| |\n");
							printf("| |                                   | |\n");							
							printf("| |    ___________________            | |\n");
							printf("| |   |                   |           | |\n");
							printf("| |   |  Configurar uma   | digite 1  | |\n");
							printf("| |   |       dieta       |           | |\n");
							printf("| |   |___________________|           | |\n");
							printf("| |                                   | |\n");
							printf("| |                                   | |\n");										
							printf("| |    ___________________            | |\n");
							printf("| |   |                   |           | |\n");
							printf("| |   |   Buscar outro    | digite 2  | |\n");
							printf("| |   |     paciente      |           | |\n");
							printf("| |   |___________________|           | |\n");									
							printf("| |                                   | |\n");
							printf("| |                                   | |\n");
							printf("| |    ___________________            | |\n");
							printf("| |   |                   |           | |\n");
							printf("| |   |     Vizualizar    | digite 3  | |\n");
							printf("| |   |     alimentos     |           | |\n");
							printf("| |   |___________________|           | |\n");
							printf("| |                                   | |\n");
							printf("| |                                   | |\n");
							printf("| |    ___________________            | |\n");
							printf("| |   |                   |           | |\n");
							printf("| |   |       Sair        | Digite 0  | |\n");
							printf("| |   |___________________|           | |\n");
							printf("| |                                   | |\n");
							printf("| |                                   | |\n");
							printf("| `-----------------------------------' |\n");
							printf("|                                       |\n");
							printf("`---------------------------------------'\n");
							scanf("%d",&acaoN[1]);
							fflush(stdin);
							switch(acaoN[1]){
								case 1: //nutri com paciente quer configurar
									editDieta=ListarDieta(auth);
									if(editDieta==-1){
										voltar=0;
									}
									else{
										system("CLS");
										printf("Iniciando a edição da dieta do(a) %s.\n",usuario[editDieta].nome);
										printf("Informações importantes:\n");
										printf("Altura: %.2f\n",usuario[editDieta].altura);
										printf("Peso: %.2f\n",usuario[editDieta].peso);
										printf("As calorias diárias máximas cadastradas para este usuário são: %.2f\n",dietaPessoa[editDieta].totalKcal);
										system("PAUSE");
									}
									while(voltar!=0){
										system("CLS");
										printf(".--------------------------------------,\n");
										printf("| .-----------------------------------, |\n");
										printf("| |                                   | |\n");
										printf("| |          (        Perfil:         | |\n");
										printf("| |           )        Nutricionista! | |\n");
										printf("| |      __..---..__                  | |\n");
										printf("| |  ,-='  /  |  \\  `=-.              | |\n");
										printf("| | :--..___________..--;             | |\n");
										printf("| |  \\.,_____________,./              | |\n");
										printf("| |                                   | |\n");
										printf("| |         Configurando dieta        | |\n");
										printf("| |___________________________________| |\n");
										printf("| |    ___________________            | |\n");
										printf("| |   |                   |           | |\n");
										printf("| |   |      Editar       | digite 1  | |\n");
										printf("| |   |   Café da Manhã   |           | |\n");
										printf("| |   |___________________|           | |\n");
										printf("| |                                   | |\n");
										printf("| |                                   | |\n");
										printf("| |    ___________________            | |\n");
										printf("| |   |                   |           | |\n");
										printf("| |   |      Editar       | digite 2  | |\n");
										printf("| |   |      Almoço       |           | |\n");
										printf("| |   |___________________|           | |\n");
										printf("| |                                   | |\n");
										printf("| |                                   | |\n");
										printf("| |    ___________________            | |\n");
										printf("| |   |                   |           | |\n");
										printf("| |   |      Editar       | digite 3  | |\n");
										printf("| |   |      Jantar       |           | |\n");
										printf("| |   |___________________|           | |\n");
										printf("| |                                   | |\n");
										printf("| |                                   | |\n");
										printf("| |    ___________________            | |\n");
										printf("| |   |                   |           | |\n");
										printf("| |   |      Voltar       | Digite 0  | |\n");
										printf("| |   |___________________|           | |\n");
										printf("| |                                   | |\n");
										printf("| `-----------------------------------' |\n");
										printf("|                                       |\n");
										printf("`---------------------------------------'\n");
										scanf("%d", &acaoN[4]);
										fflush(stdin);
										switch(acaoN[4]){
											case 1:
												system("CLS");
												printf(".--------------------------------------,\n");
												printf("| .-----------------------------------, |\n");
												printf("| |                                   | |\n");
												printf("| |          (        Perfil:         | |\n");
												printf("| |           )        Nutricionista! | |\n");
												printf("| |      __..---..__                  | |\n");
												printf("| |  ,-='  /  |  \\  `=-.              | |\n");
												printf("| | :--..___________..--;             | |\n");
												printf("| |  \\.,_____________,./              | |\n");
												printf("| |                                   | |\n");
												printf("| |         Configurando dieta        | |\n");
												printf("| |___________________________________| |\n");
												printf("| |                                   | |\n");
												printf("| |        ___________________        | |\n");
												printf("| |       |                   |       | |\n");
												printf("| |       |   Cafe da manhã:  |       | |\n");
												printf("| |       |___________________|       | |\n");
												printf("| |                                   | |\n");
												printf("| `-----------------------------------' |\n");
												printf("|                                       |\n");
												printf("`---------------------------------------'\n");
												if(usuario[editDieta].config==1){
													printf("Esse é um usuário recém cadastrado, não existem dietas configuradas, iniciar uma? (S/N): ");
													scanf("%c",&ConfirmarEdicao);
													fflush(stdin);
												}
												else if(usuario[editDieta].config==2){
													printf("Este é o café da manhã atualmente configurado: \n\n");
													for(i=0;i<100;i++){
														if(dietaPessoa[editDieta].alimentoCafe[i].exist==1){
															printf("%s - %.2f Kcal",dietaPessoa[editDieta].alimentoCafe[i].nomeAlimento,dietaPessoa[editDieta].alimentoCafe[i].kcalAlimento);															
															printf("\n");
														}	
													}
													printf("\n");
													printf("Deseja realmente editar o café da manhã? (S/N): ");
													scanf("%c",&ConfirmarEdicao);
												}												
												fflush(stdin);
												if(ConfirmarEdicao == 'S' || ConfirmarEdicao == 's'){
													for(i=0;i<100;i++){
														strcpy(dietaPessoa[editDieta].alimentoCafe[i].nomeAlimento,"");
														dietaPessoa[editDieta].alimentoCafe[i].exist=0;
													}
													printf("Insira um alimento:\n");
													gets(tentativaAlimento);
													for(i=0;i<100;i++){
														if(i==99){
															if(stricmp(tentativaAlimento,alimento[i].nomeAlimento)==0){
																strcpy(dietaPessoa[editDieta].alimentoCafe[0].nomeAlimento,tentativaAlimento);
																dietaPessoa[editDieta].alimentoCafe[0].kcalAlimento=alimento[i].kcalAlimento;
																dietaPessoa[editDieta].alimentoCafe[0].exist=1;
																break;
															}
															printf("Alimento não cadastrado na base de dados. Deseja cadastrar? (S/N): ");
															scanf("%c",&ConfirmarEdicao);
															fflush(stdin);
															if(ConfirmarEdicao == 'S' || ConfirmarEdicao == 's'){
																printf("Insira o nome do alimento: ");
																for(j=0;j<100;j++){
																	if(alimento[j].exist==0){
																		gets(alimento[j].nomeAlimento);
																		printf("Insira o valor calorico do alimento em 100g: ");
																		scanf("%f",&alimento[j].kcalAlimento);
																		dietaPessoa[editDieta].alimentoCafe[0].kcalAlimento=alimento[j].kcalAlimento;
																		fflush(stdin);
																		alimento[j].exist=1;
																		strcpy(dietaPessoa[editDieta].alimentoCafe[0].nomeAlimento,alimento[j].nomeAlimento);
																		dietaPessoa[editDieta].alimentoCafe[0].exist=1;
																		break;
																	}
																}
															}
														}
														if(stricmp(tentativaAlimento,alimento[i].nomeAlimento)==0){
															strcpy(dietaPessoa[editDieta].alimentoCafe[0].nomeAlimento,tentativaAlimento);
															dietaPessoa[editDieta].alimentoCafe[0].kcalAlimento=alimento[i].kcalAlimento;
															dietaPessoa[editDieta].alimentoCafe[0].exist=1;
															break;
														}																												
													}													
													printf("Deseja adicionar outro alimento ao café da manhã? (S/N): ");
													scanf("%c",&ConfirmarEdicao);
													fflush(stdin);
													if(ConfirmarEdicao == 'S' || ConfirmarEdicao == 's'){
														a=1;
														do{
															printf("Insira um alimento:\n");
															gets(tentativaAlimento);
															for(i=0;i<100;i++){
																if(i==99){
																	if(stricmp(tentativaAlimento,alimento[i].nomeAlimento)==0){
																		strcpy(dietaPessoa[editDieta].alimentoCafe[a].nomeAlimento,tentativaAlimento);
																		dietaPessoa[editDieta].alimentoCafe[a].kcalAlimento=alimento[i].kcalAlimento;
																		dietaPessoa[editDieta].alimentoCafe[a].exist=1;
																		a++;
																		break;
																	}
																	printf("Alimento não cadastrado na base de dados. Deseja cadastrar? (S/N): ");
																	scanf("%c",&ConfirmarEdicao);
																	fflush(stdin);
																	if(ConfirmarEdicao == 'S' || ConfirmarEdicao == 's'){
																		printf("Insira o nome do alimento: ");
																		for(j=0;j<100;j++){
																			if(alimento[j].exist==0){
																				gets(alimento[j].nomeAlimento);
																				printf("Insira o valor calorico do alimento em 100g: ");
																				scanf("%f",&alimento[j].kcalAlimento);
																				dietaPessoa[editDieta].alimentoCafe[a].kcalAlimento=alimento[j].kcalAlimento;
																				fflush(stdin);
																				alimento[j].exist=1;
																				strcpy(dietaPessoa[editDieta].alimentoCafe[a].nomeAlimento,alimento[j].nomeAlimento);
																				dietaPessoa[editDieta].alimentoCafe[a].exist=1;
																				a++;
																				break;
																			}
																		}
																	}
																	else{
																		break;
																	}
																}
																if(stricmp(tentativaAlimento,alimento[i].nomeAlimento)==0){
																	strcpy(dietaPessoa[editDieta].alimentoCafe[a].nomeAlimento,tentativaAlimento);
																	dietaPessoa[editDieta].alimentoCafe[a].kcalAlimento=alimento[i].kcalAlimento;
																	dietaPessoa[editDieta].alimentoCafe[a].exist=1;
																	a++;
																	break;
																}																												
															}															
															printf("Deseja adicionar outro alimento ao café da manhã? (S/N): ");
															scanf("%c",&ConfirmarEdicao);
															fflush(stdin);													
														}while(ConfirmarEdicao== 'S' || ConfirmarEdicao == 's');													
														printf("Insira os preparos:\n");													
														gets(dietaPessoa[editDieta].preparoCafe);													
													}
													dietaPessoa[editDieta].kcalCafe=0;													
													for(i=0;i<100;i++){
														if(dietaPessoa[editDieta].alimentoCafe[i].exist==1){
															dietaPessoa[editDieta].kcalCafe=dietaPessoa[editDieta].kcalCafe+dietaPessoa[editDieta].alimentoCafe[i].kcalAlimento;
														}														
													}
													dietaPessoa[editDieta].totalKcal=dietaPessoa[editDieta].kcalCafe+dietaPessoa[editDieta].kcalAlmoco+dietaPessoa[editDieta].kcalJantar;
													printf("A nova dieta tem um valor calorico total de: %.2f\n",dietaPessoa[editDieta].totalKcal);
													printf("O café da manhã tem um valor calorico total de: %.2f\n",dietaPessoa[editDieta].kcalCafe);
													printf("Pressione 0 para voltar: ");
													scanf("%d",&voltar);
													
												}
											break;
											case 2:
												system("CLS");
												printf(".--------------------------------------,\n");
												printf("| .-----------------------------------, |\n");
												printf("| |                                   | |\n");
												printf("| |          (        Perfil:         | |\n");
												printf("| |           )        Nutricionista! | |\n");
												printf("| |      __..---..__                  | |\n");
												printf("| |  ,-='  /  |  \\  `=-.              | |\n");
												printf("| | :--..___________..--;             | |\n");
												printf("| |  \\.,_____________,./              | |\n");
												printf("| |                                   | |\n");
												printf("| |         Configurando dieta        | |\n");
												printf("| |___________________________________| |\n");
												printf("| |                                   | |\n");
												printf("| |        ___________________        | |\n");
												printf("| |       |                   |       | |\n");
												printf("| |       |      Almoço:      |       | |\n");
												printf("| |       |___________________|       | |\n");
												printf("| |                                   | |\n");
												printf("| `-----------------------------------' |\n");
												printf("|                                       |\n");
												printf("`---------------------------------------'\n");
												if(usuario[editDieta].config==1){
													printf("Esse é um usuário recém cadastrado, não existem dietas configuradas, iniciar uma? (S/N): ");
													scanf("%c",&ConfirmarEdicao);
													fflush(stdin);
												}
												else if(usuario[editDieta].config==2){
													printf("Este é o almoço atualmente configurado: \n\n");
													for(i=0;i<100;i++){
														if(dietaPessoa[editDieta].alimentoAlmoco[i].exist==1){
															printf("%s - %.2f Kcal",dietaPessoa[editDieta].alimentoAlmoco[i].nomeAlimento,dietaPessoa[editDieta].alimentoAlmoco[i].kcalAlimento);															
															printf("\n");
														}	
													}
													printf("\n");
													printf("Deseja realmente editar o almoço? (S/N): ");
													scanf("%c",&ConfirmarEdicao);
												}												
												fflush(stdin);
												if(ConfirmarEdicao == 'S' || ConfirmarEdicao == 's'){
													for(i=0;i<100;i++){
														strcpy(dietaPessoa[editDieta].alimentoAlmoco[i].nomeAlimento,"");
														dietaPessoa[editDieta].alimentoAlmoco[i].exist=0;
													}
													printf("Insira um alimento:\n");
													gets(tentativaAlimento);
													for(i=0;i<100;i++){
														if(i==99){
															if(stricmp(tentativaAlimento,alimento[i].nomeAlimento)==0){
																strcpy(dietaPessoa[editDieta].alimentoAlmoco[0].nomeAlimento,tentativaAlimento);
																dietaPessoa[editDieta].alimentoAlmoco[0].kcalAlimento=alimento[i].kcalAlimento;
																dietaPessoa[editDieta].alimentoAlmoco[0].exist=1;
																break;
															}
															printf("Alimento não cadastrado na base de dados. Deseja cadastrar? (S/N): ");
															scanf("%c",&ConfirmarEdicao);
															fflush(stdin);
															if(ConfirmarEdicao == 'S' || ConfirmarEdicao == 's'){
																printf("Insira o nome do alimento: ");
																for(j=0;j<100;j++){
																	if(alimento[j].exist==0){
																		gets(alimento[j].nomeAlimento);
																		printf("Insira o valor calorico do alimento em 100g: ");
																		scanf("%f",&alimento[j].kcalAlimento);
																		dietaPessoa[editDieta].alimentoAlmoco[0].kcalAlimento=alimento[j].kcalAlimento;
																		fflush(stdin);
																		alimento[j].exist=1;
																		strcpy(dietaPessoa[editDieta].alimentoAlmoco[0].nomeAlimento,alimento[j].nomeAlimento);
																		dietaPessoa[editDieta].alimentoAlmoco[0].exist=1;
																		break;
																	}
																}
															}
														}
														if(stricmp(tentativaAlimento,alimento[i].nomeAlimento)==0){
															strcpy(dietaPessoa[editDieta].alimentoAlmoco[0].nomeAlimento,tentativaAlimento);
															dietaPessoa[editDieta].alimentoAlmoco[0].kcalAlimento=alimento[i].kcalAlimento;
															dietaPessoa[editDieta].alimentoAlmoco[0].exist=1;
															break;
														}																												
													}													
													printf("Deseja adicionar outro alimento ao almoço? (S/N): ");
													scanf("%c",&ConfirmarEdicao);
													fflush(stdin);
													if(ConfirmarEdicao == 'S' || ConfirmarEdicao == 's'){
														a=1;
														do{
															printf("Insira um alimento:\n");
															gets(tentativaAlimento);
															for(i=0;i<100;i++){
																if(i==99){
																	if(stricmp(tentativaAlimento,alimento[i].nomeAlimento)==0){
																		strcpy(dietaPessoa[editDieta].alimentoAlmoco[a].nomeAlimento,tentativaAlimento);
																		dietaPessoa[editDieta].alimentoAlmoco[a].kcalAlimento=alimento[i].kcalAlimento;
																		dietaPessoa[editDieta].alimentoAlmoco[a].exist=1;
																		a++;
																		break;
																	}
																	printf("Alimento não cadastrado na base de dados. Deseja cadastrar? (S/N): ");
																	scanf("%c",&ConfirmarEdicao);
																	fflush(stdin);
																	if(ConfirmarEdicao == 'S' || ConfirmarEdicao == 's'){
																		printf("Insira o nome do alimento: ");
																		for(j=0;j<100;j++){
																			if(alimento[j].exist==0){
																				gets(alimento[j].nomeAlimento);
																				printf("Insira o valor calorico do alimento em 100g: ");
																				scanf("%f",&alimento[j].kcalAlimento);
																				dietaPessoa[editDieta].alimentoAlmoco[a].kcalAlimento=alimento[j].kcalAlimento;
																				fflush(stdin);
																				alimento[j].exist=1;
																				strcpy(dietaPessoa[editDieta].alimentoAlmoco[a].nomeAlimento,alimento[j].nomeAlimento);
																				dietaPessoa[editDieta].alimentoAlmoco[a].exist=1;
																				a++;
																				break;
																			}
																		}
																	}
																	else{
																		break;
																	}
																}
																if(stricmp(tentativaAlimento,alimento[i].nomeAlimento)==0){
																	strcpy(dietaPessoa[editDieta].alimentoAlmoco[a].nomeAlimento,tentativaAlimento);
																	dietaPessoa[editDieta].alimentoAlmoco[a].kcalAlimento=alimento[i].kcalAlimento;
																	dietaPessoa[editDieta].alimentoAlmoco[a].exist=1;
																	a++;
																	break;
																}																												
															}															
															printf("Deseja adicionar outro alimento ao almoço? (S/N): ");
															scanf("%c",&ConfirmarEdicao);
															fflush(stdin);													
														}while(ConfirmarEdicao== 'S' || ConfirmarEdicao == 's');													
														printf("Insira os preparos:\n");													
														gets(dietaPessoa[editDieta].preparoAlmoco);														
													}
													dietaPessoa[editDieta].kcalAlmoco=0;													
													for(i=0;i<100;i++){
														if(dietaPessoa[editDieta].alimentoAlmoco[i].exist==1){
															dietaPessoa[editDieta].kcalAlmoco=dietaPessoa[editDieta].kcalAlmoco+dietaPessoa[editDieta].alimentoAlmoco[i].kcalAlimento;
														}														
													}
													dietaPessoa[editDieta].totalKcal=dietaPessoa[editDieta].kcalCafe+dietaPessoa[editDieta].kcalAlmoco+dietaPessoa[editDieta].kcalJantar;
													printf("A nova dieta tem um valor calorico total de: %.2f\n",dietaPessoa[editDieta].totalKcal);
													printf("O almoço tem um valor calorico total de: %.2f\n",dietaPessoa[editDieta].kcalAlmoco);
													printf("Pressione 0 para voltar: ");
													scanf("%d",&voltar);													
												}
												
											break;
											case 3:
												system("CLS");
												printf(".--------------------------------------,\n");
												printf("| .-----------------------------------, |\n");
												printf("| |                                   | |\n");
												printf("| |          (        Perfil:         | |\n");
												printf("| |           )        Nutricionista! | |\n");
												printf("| |      __..---..__                  | |\n");
												printf("| |  ,-='  /  |  \\  `=-.              | |\n");
												printf("| | :--..___________..--;             | |\n");
												printf("| |  \\.,_____________,./              | |\n");
												printf("| |                                   | |\n");
												printf("| |         Configurando dieta        | |\n");
												printf("| |___________________________________| |\n");
												printf("| |                                   | |\n");
												printf("| |        ___________________        | |\n");
												printf("| |       |                   |       | |\n");
												printf("| |       |      Jantar:      |       | |\n");
												printf("| |       |___________________|       | |\n");
												printf("| |                                   | |\n");
												printf("| `-----------------------------------' |\n");
												printf("|                                       |\n");
												printf("`---------------------------------------'\n");
												if(usuario[editDieta].config==1){
													printf("Esse é um usuário recém cadastrado, não existem dietas configuradas, iniciar uma? (S/N): ");
													scanf("%c",&ConfirmarEdicao);
													fflush(stdin);
												}
												else if(usuario[editDieta].config==2){
													printf("Este é o jantar atualmente configurado: \n\n");
													for(i=0;i<100;i++){
														if(dietaPessoa[editDieta].alimentoJantar[i].exist==1){
															printf("%s - %.2f Kcal",dietaPessoa[editDieta].alimentoJantar[i].nomeAlimento,dietaPessoa[editDieta].alimentoJantar[i].kcalAlimento);															
															printf("\n");
														}	
													}
													printf("\n");
													printf("Deseja realmente editar o jantar? (S/N): ");
													scanf("%c",&ConfirmarEdicao);
												}												
												fflush(stdin);
												if(ConfirmarEdicao == 'S' || ConfirmarEdicao == 's'){
													for(i=0;i<100;i++){
														strcpy(dietaPessoa[editDieta].alimentoJantar[i].nomeAlimento,"");
														dietaPessoa[editDieta].alimentoJantar[i].exist=0;
													}
													printf("Insira um alimento:\n");
													gets(tentativaAlimento);
													for(i=0;i<100;i++){
														if(i==99){
															if(stricmp(tentativaAlimento,alimento[i].nomeAlimento)==0){
																strcpy(dietaPessoa[editDieta].alimentoJantar[0].nomeAlimento,tentativaAlimento);
																dietaPessoa[editDieta].alimentoJantar[0].kcalAlimento=alimento[i].kcalAlimento;
																dietaPessoa[editDieta].alimentoJantar[0].exist=1;
																break;
															}
															printf("Alimento não cadastrado na base de dados. Deseja cadastrar? (S/N): ");
															scanf("%c",&ConfirmarEdicao);
															fflush(stdin);
															if(ConfirmarEdicao == 'S' || ConfirmarEdicao == 's'){
																printf("Insira o nome do alimento: ");
																for(j=0;j<100;j++){
																	if(alimento[j].exist==0){
																		gets(alimento[j].nomeAlimento);
																		printf("Insira o valor calorico do alimento em 100g: ");
																		scanf("%f",&alimento[j].kcalAlimento);
																		dietaPessoa[editDieta].alimentoJantar[0].kcalAlimento=alimento[j].kcalAlimento;
																		fflush(stdin);
																		alimento[j].exist=1;
																		strcpy(dietaPessoa[editDieta].alimentoJantar[0].nomeAlimento,alimento[j].nomeAlimento);
																		dietaPessoa[editDieta].alimentoJantar[0].exist=1;
																		break;
																	}
																}
															}
														}
														if(stricmp(tentativaAlimento,alimento[i].nomeAlimento)==0){
															strcpy(dietaPessoa[editDieta].alimentoJantar[0].nomeAlimento,tentativaAlimento);
															dietaPessoa[editDieta].alimentoJantar[0].kcalAlimento=alimento[i].kcalAlimento;
															dietaPessoa[editDieta].alimentoJantar[0].exist=1;
															break;
														}																												
													}													
													printf("Deseja adicionar outro alimento ao jantar? (S/N): ");
													scanf("%c",&ConfirmarEdicao);
													fflush(stdin);
													if(ConfirmarEdicao == 'S' || ConfirmarEdicao == 's'){
														a=1;
														do{
															printf("Insira um alimento:\n");
															gets(tentativaAlimento);
															for(i=0;i<100;i++){
																if(i==99){
																	if(stricmp(tentativaAlimento,alimento[i].nomeAlimento)==0){
																		strcpy(dietaPessoa[editDieta].alimentoJantar[a].nomeAlimento,tentativaAlimento);
																		dietaPessoa[editDieta].alimentoJantar[a].kcalAlimento=alimento[i].kcalAlimento;
																		dietaPessoa[editDieta].alimentoJantar[a].exist=1;
																		a++;
																		break;
																	}
																	printf("Alimento não cadastrado na base de dados. Deseja cadastrar? (S/N): ");
																	scanf("%c",&ConfirmarEdicao);
																	fflush(stdin);
																	if(ConfirmarEdicao == 'S' || ConfirmarEdicao == 's'){
																		printf("Insira o nome do alimento: ");
																		for(j=0;j<100;j++){
																			if(alimento[j].exist==0){
																				gets(alimento[j].nomeAlimento);
																				printf("Insira o valor calorico do alimento em 100g: ");
																				scanf("%f",&alimento[j].kcalAlimento);
																				dietaPessoa[editDieta].alimentoJantar[a].kcalAlimento=alimento[j].kcalAlimento;
																				fflush(stdin);
																				alimento[j].exist=1;
																				strcpy(dietaPessoa[editDieta].alimentoJantar[a].nomeAlimento,alimento[j].nomeAlimento);
																				dietaPessoa[editDieta].alimentoJantar[a].exist=1;
																				a++;
																				break;
																			}
																		}
																	}
																	else{
																		break;
																	}
																}
																if(stricmp(tentativaAlimento,alimento[i].nomeAlimento)==0){
																	strcpy(dietaPessoa[editDieta].alimentoJantar[a].nomeAlimento,tentativaAlimento);
																	dietaPessoa[editDieta].alimentoJantar[a].kcalAlimento=alimento[i].kcalAlimento;
																	dietaPessoa[editDieta].alimentoJantar[a].exist=1;
																	a++;
																	break;
																}																												
															}															
															printf("Deseja adicionar outro alimento ao jantar? (S/N): ");
															scanf("%c",&ConfirmarEdicao);
															fflush(stdin);													
														}while(ConfirmarEdicao== 'S' || ConfirmarEdicao == 's');													
														printf("Insira os preparos:\n");													
														gets(dietaPessoa[editDieta].preparoJantar);														
													}
													dietaPessoa[editDieta].kcalJantar=0;													
													for(i=0;i<100;i++){
														if(dietaPessoa[editDieta].alimentoJantar[i].exist==1){
															dietaPessoa[editDieta].kcalJantar=dietaPessoa[editDieta].kcalJantar+dietaPessoa[editDieta].alimentoJantar[i].kcalAlimento;
														}														
													}
													dietaPessoa[editDieta].totalKcal=dietaPessoa[editDieta].kcalCafe+dietaPessoa[editDieta].kcalAlmoco+dietaPessoa[editDieta].kcalJantar;
													printf("A nova dieta tem um valor calorico total de: %.2f\n",dietaPessoa[editDieta].totalKcal);
													printf("O jantar tem um valor calorico total de: %.2f\n",dietaPessoa[editDieta].kcalJantar);
													usuario[editDieta].config=2;
													printf("Pressione 0 para voltar: ");
													scanf("%d",&voltar);													
												}												
											break;
											case 0:
												voltar=0;
											break;
											default:
												voltar=1;
											break;
										}
										if(acaoN[4]!=0){
											voltar=1;
										}										
									}
								break;//nutri com paciente quer configurar
								case 2://nutri com paciente quer outro paciente
									busca=buscapaciente(auth);
								break;//nutri com paciente quer outro paciente
								case 3://nutri com paciente quer listar comidas
									system("CLS");
												printf(".--------------------------------------,\n");
												printf("| .-----------------------------------, |\n");
												printf("| |                                   | |\n");
												printf("| |          (        Perfil:         | |\n");
												printf("| |           )        Nutricionista! | |\n");
												printf("| |      __..---..__                  | |\n");
												printf("| |  ,-='  /  |  \\  `=-.              | |\n");
												printf("| | :--..___________..--;             | |\n");
												printf("| |  \\.,_____________,./              | |\n");
												printf("| |                                   | |\n");
												printf("| |         LISTANDO ALIMENTOS        | |\n");
												printf("| |___________________________________| |\n");
												printf("| |                                   | |\n");
												printf("| |        ___________________        | |\n");
												printf("| |       |                   |       | |\n");
												printf("| |       |      BASE DE      |       | |\n");
												printf("| |       |       DADOS       |       | |\n");
												printf("| |       |___________________|       | |\n");
												printf("| |                                   | |\n");
												printf("| `-----------------------------------' |\n");
												printf("|                                       |\n");
												printf("`---------------------------------------'\n");
												for(i=0;i<100;i++){
													if(alimento[i].exist==1){
														puts(alimento[i].nomeAlimento);
													}
												}
												printf("Deseja adicionar outro alimento à lista de alimentos? (S/N): ");
												scanf("%c",&ConfirmarEdicao);
												fflush(stdin);
												if(ConfirmarEdicao == 'S' || ConfirmarEdicao == 's'){
													do{
														printf("Insira o nome do alimento: ");
														for(i=0;i<100;i++){
															if(alimento[i].exist==0){
																gets(alimento[i].nomeAlimento);
																printf("Insira o valor calorico do alimento em 100g: ");
																scanf("%f",&alimento[i].kcalAlimento);
																fflush(stdin);
																alimento[i].exist=1;
																break;
															}
														}
														printf("Deseja adicionar outro alimento à lista de alimentos? (S/N): ");
														scanf("%c",&ConfirmarEdicao);
														fflush(stdin);
													}while(ConfirmarEdicao == 'S' || ConfirmarEdicao == 's');													
												}
												printf("Pressione qualquer tecla para voltar: ");
												getchar();
												
								break;//nutri com paciente quer listar comidas
								case 0://nutri com paciente quer sair								
									voltar=0;
								break;//nutri com paciente quer sair
								default:
									voltar=1;
								break;
							}//chave do switch - acao do nutri
							if(acaoN[1]!=0){
							voltar=1;	
							}
						}
						voltar=1;
					break;// FIM DO CASO: NUTRICIONISTA - POSSUI CADASTRO 
					case 2:// INICIO DO CASO: NUTRICIONISTA - NÃO POSSUI CADASTRO
						system("CLS");
						printf(
	    					"+--------------------+\n"
	    					"¦  Tela de cadastro  ¦\n"
	    					"+--------------------+\n"
						);
						printf("Vamos iniciar seu cadastro:\n");
						for(i=0;i<100;i++){
							if(nutricionista[i].existNutri==0){
								printf("Insira seu nome: ");
								scanf("%s",&nutricionista[i].nome);
								printf("Insira seu e-mail: ");
								scanf("%s", &nutricionista[i].email);
								printf("Insira sua senha: ");
								scanf("%s", &nutricionista[i].senha);
								system("CLS");
								printf(
			    					"+----------------------------+\n"
			    					"¦  Configurações adicionais  ¦\n"
			    					"+----------------------------+\n"
								);
								printf("Insira seu CRM: ");
								scanf("%s", &nutricionista[i].crm);
								nutricionista[i].existNutri=1;
								nutricionista[i].configNutri=0;
								nutricionista[i].cod=i;
								auth=i;
								i=100;
							}
						}
						printf("Conta criada com sucesso!\n");
						fflush(stdin);				 
					break;// FIM DO CASO: NUTRICIONISTA - NÃO POSSUI CADASTRO 
					default:
						voltar=1;
					break;
				}//Chave do switch cadastro DO NUTRICIONISTA.
			break;// FIM DO CASO: NUTRICIONISTA
			default:
				voltar=1;
			break;
		}//Chave do switch classe
	}
}//Chave da função MAIN();




void home(){
	system("CLS");
	printf(".--------------------------------------,\n");
	printf("| .-----------------------------------, |\n");
	printf("| |                                   | |\n");
	printf("| |          (         Bem vindo(a)   | |\n");
	printf("| |           )             ao        | |\n");
	printf("| |      __..---..__   PersonalNutri  | |\n");
	printf("| |  ,-='  /  |  \\  `=-.              | |\n");
	printf("| | :--..___________..--;             | |\n");
	printf("| |  \\.,_____________,./              | |\n");
	printf("| |                                   | |\n");
	printf("| |___________________________________| |\n");
	printf("| |                                   | |\n");
	printf("| |    ___________________            | |\n");
	printf("| |   |                   |           | |\n");
	printf("| |   |   Sou paciente    | digite 1  | |\n");
	printf("| |   |___________________|           | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |    ___________________            | |\n");
	printf("| |   |                   |           | |\n");
	printf("| |   | Sou nutricionista | digite 2  | |\n");
	printf("| |   |___________________|           | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| `-----------------------------------' |\n");
	printf("|                                       |\n");
	printf("`---------------------------------------'\n");
}
void FuncCadastro(){
		system("CLS");
	printf(".--------------------------------------,\n");
	printf("| .-----------------------------------, |\n");
	printf("| |                                   | |\n");
	printf("| |          (         Bem vindo(a)   | |\n");
	printf("| |           )             ao        | |\n");
	printf("| |      __..---..__   PersonalNutri  | |\n");
	printf("| |  ,-='  /  |  \\  `=-.              | |\n");
	printf("| | :--..___________..--;             | |\n");
	printf("| |  \\.,_____________,./              | |\n");
	printf("| |                                   | |\n");
	printf("| |___________________________________| |\n");
	printf("| |                                   | |\n");
	printf("| |   _____________________           | |\n");
	printf("| |  |                     |          | |\n");
	printf("| |  | Já possui cadastro? | digite 1 | |\n");
	printf("| |  |_____________________|          | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |   ____________________            | |\n");
	printf("| |  |                    |           | |\n");
	printf("| |  | Quer se cadastrar? | digite 2  | |\n");
	printf("| |  |____________________|           | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| `-----------------------------------' |\n");
	printf("|                                       |\n");
	printf("`---------------------------------------'\n");
}
int verificarLogin(char email[],char senha[]){
	int i,auth=-1;
	for(i=0;i<100;i++){
			if(usuario[i].exist==1){
				if(strcmp(usuario[i].email,email)==0 && strcmp(usuario[i].senha,senha)==0){
					auth=i;
					i=100;
				}
			}
			if(nutricionista[i].existNutri==1){
				if(strcmp(nutricionista[i].email,email)==0 && strcmp(nutricionista[i].senha,senha)==0){
					auth=i;
					i=100;
				}				
			}
	}
	return auth;
}
int buscapaciente(int auth){
	int i;
	system("CLS");
	for (i = 0; i < 10001; i++){
		printf("\rProcurando por paciente próximo %d%%", i/100);
	}
	printf("\n");
	for(i=0;i<100;i++){
		if(i==99){
			printf("Não existe nenhum paciente cadastrado a espera de atendimento. Tente novamente mais tarde.\n");
			system("PAUSE");
			return -1;
		}
		if(usuario[i].config==0){
			printf("Paciente encontrado! Agora você será responsável por administrar a dieta do %s!\n",usuario[i].nome);
			usuario[i].config=1;
			nutricionista[auth].configNutri=1;
			usuario[i].associacao=nutricionista[auth].cod;
			system("PAUSE");
			return i;
		}
										
	}
}
int ListarDieta(int auth){
	int i,voltar=1,cont=1;
	system("CLS");
	printf(".--------------------------------------,\n");
	printf("| .-----------------------------------, |\n");
	printf("| |                                   | |\n");
	printf("| |          (        Perfil:         | |\n");
	printf("| |           )        Nutricionista! | |\n");
	printf("| |      __..---..__                  | |\n");
	printf("| |  ,-='  /  |  \\  `=-.              | |\n");
	printf("| | :--..___________..--;             | |\n");
	printf("| |  \\.,_____________,./              | |\n");
	printf("| |                                   | |\n");
	printf("| |       Pressione 0 para voltar     | |\n");
	printf("| |___________________________________| |\n");
	printf("| |                                   | |\n");
	printf("| |                                   | |\n");
	printf("| |        ___________________        | |\n");
	printf("| |       |                   |       | |\n");
	printf("| |       |   Visualizando:   |       | |\n");
	printf("| |       |      Dietas       |       | |\n");
	printf("| |       |___________________|       | |\n");
	printf("| |                                   | |\n");
	printf("| `-----------------------------------' |\n");
	printf("|                                       |\n");
	printf("`---------------------------------------'\n");
	for(i=0;i<100;i++){
		if(usuario[i].associacao==nutricionista[auth].cod){
			while(voltar!=0){
				printf("Pressione %d para editar a dieta do(a) %s. E -1 para avançar: ",cont,usuario[i].nome);
				scanf("%d",&acaoN[3]);
				fflush(stdin);
				if(acaoN[3]==cont){
					return i;
				}
				if(acaoN[3]==-1){
					if(usuario[i+1].associacao==nutricionista[auth].cod){
						voltar=0;
					}
					
				}
				if(acaoN[3]==0){
					return -1;
				}
			}
			cont++;
			voltar=1;

		}
	}
	return 15;
}


