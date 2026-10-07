#include <iostream>
#include <cstdlib>
#include "httplib.h"

int main() {
    httplib::Server svr;

    // Route principale '/'
    svr.Get("/", [](const httplib::Request&, httplib::Response& res) {
        std::string html = 
            "<h1>=== E-Commerce Engine (C++) - Ali CHAFIK ===</h1>"
            "<h3>--- Contenu du Panier ---</h3>"
            "<ul>"
            "<li>PC Portable Dell + [Emballage Cadeau] : 1203.5 EUR</li>"
            "<li>Smartphone Galaxy (-10%) + [Emballage Cadeau] : 723.5 EUR</li>"
            "</ul>"
            "<hr>"
            "<h2>TOTAL : 1927 EUR</h2>"
            "<p><strong>[PAIEMENT]</strong> 1927 EUR regles via Carte Bdf (8888)</p>"
            "<p style='color:green;'>Commande validee avec succes pour Ali CHAFIK.</p>";
        
        res.set_content(html, "text/html; charset=utf-8");
    });

    // Endpoint Healthcheck pour Azure
    svr.Get("/health", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("OK", "text/plain");
    });

    // Lecture du port depuis l'environnement ou port 5050 par defaut
    const char* port_env = std::getenv("WEBSITES_PORT");
    if (!port_env) port_env = std::getenv("PORT");
    int port = port_env ? std::atoi(port_env) : 5050;

    std::cout << "Serveur E-Commerce C++ en ecoute sur le port " << port << "..." << std::endl;
    
    svr.listen("0.0.0.0", port);

    return 0;
}
