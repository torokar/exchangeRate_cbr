// #include "getFromPostgres.h"
// #include <pqxx/pqxx>
// #include <QDebug>

// void readDataTable()
// {
//     try {
//         pqxx::connection conn(
//             "host=localhost "
//             "port=5432 "
//             "dbname=mydb "
//             "user=service "
//             "password=11111111 "
//             "options='-c client_encoding=UTF8'"
//             );

//         if (conn.is_open()) {
//             pqxx::work txn(conn);
//             pqxx::result res = txn.exec("SELECT CharCode, NameCurrency, Value, "
//                                         "Date FROM exdc ORDER BY Date DESC");



//         }
//     } catch (const std::exception& e) {
//         qDebug() << "Error:" << e.what();
//     }



// }
