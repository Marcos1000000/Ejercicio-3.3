//programa en C para consultar los datos de la base de datos
//#include <my_global.h>
#include <mysql.h>
#include <string.h>

int main(int argc, char **argv)
{
	MYSQL *conn;
	int err;
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	char consulta [80];
	char nombre[60];
	conn = mysql_init(NULL);
	if (conn==NULL)
	{
		printf ("Error al crear la conexión: %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	conn = mysql_real_connect (conn, "localhost","root", "mysql", "bd",0, NULL, 0);
	if (conn==NULL)
	{
		printf ("Error al inicializar la conexión: %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	err=mysql_query (conn, "SELECT Fecha FROM where Jugador.Nombre="nombre"AND Njugador1="nombre"AND Njugador2="nombre);
	if (err!=0)
	{
		printf ("Error al consultar datos de la base %u %s\n", mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	/*
	. . .
	*/
	//recogemos el resultado de la consulta
	resultado = mysql_store_result (conn);

	row = mysql_fetch_row (resultado);
	if (row == NULL)
		printf ("No se han obtenido datos en la consulta\n");
	else
		while (row !=NULL)
	{
			// las columnas 0,1,2, 3 y 4 contienen (socioID,nombre,direccion,telefono,categoria);
			printf ("Telefono: %s Nombre: %s\n",
					row[3], row[1]);
			// obtenemos la siguiente fila
			row = mysql_fetch_row (resultado);
	}
		// cerrar la conexión con el servidor MYSQL
		mysql_close (conn);
}