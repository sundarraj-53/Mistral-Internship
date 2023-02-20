#include "mainwindow.h"33
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget window;
    window.setWindowTitle("Registration Form");
    // Create the form fields
    QT_FEATURE_label *tzname = new QT_FEATURE_label();
    QT_FEATURE_label *r = new QT_FEATURE_label()
    QLineEdit *emailField = new QLineEdit();
    QSpinBox *ageField = new QSpinBox();
    QComboBox *genderField = new QComboBox();
    genderField->addItem("Male");
    genderField->addItem("Female");
    genderField->addItem("Other");
    QTextEdit *addressField = new QTextEdit();

    // Add the form fields to the layout
    formLayout->addRow("First Name:", firstNameField);
    formLayout->addRow("Last Name:", lastNameField);
    formLayout->addRow("Email:", emailField);
    formLayout->addRow("Age:", ageField);
    formLayout->addRow("Gender:", genderField);
    formLayout->addRow("Address:", addressField);

    // Create the submit button
    QPushButton *submitButton = new QPushButton("Submit");

    // Add the form layout and submit button to the main window
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(submitButton);
    window.setLayout(mainLayout);

    // Connect the submit button to a slot that processes the form data
    QObject::connect(submitButton, &QPushButton::clicked, [&](){
        QString firstName = firstNameField->text();
        QString lastName = lastNameField->text();
        QString email = emailField->text();
        int age = ageField->value();
        QString gender = genderField->currentText();
        QString address = addressField->toPlainText();

        // Validate the form data
        if (firstName.isEmpty() || lastName.isEmpty() || email.isEmpty()) {
            QMessageBox::warning(&window, "Error", "Please enter all required fields.");
            return;
        }

        // Save the form data to the database
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("registration.db");
        if (!db.open()) {
            QMessageBox::critical(&window, "Error", "Could not open database.");
            return;
        }
        QSqlQuery query;
        query.prepare("INSERT INTO users (first_name, last_name, email, age, gender, address) "
                      "VALUES (:first_name, :last_name, :email, :age, :gender, :address)");
        query.bindValue(":first_name", firstName);
        query.bindValue(":last_name", lastName);
        query.bindValue(":email", email);
        query.bindValue(":age", age);
        query.bindValue(":gender", gender);
        query.bindValue(":address", address);
        if (!query.exec()) {
            QMessageBox::critical(&window, "Error", "Could not save data to database.");
            return;
        }

        QMessageBox::information(&window, "Success", "Data saved to database.");
    });
    MainWindow w;
    w.show();
    return a.exec();

}
