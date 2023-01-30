package com.oopclass.oopexamplejava.controllers;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;

@Controller
public class MainController {

    @GetMapping("/")
    public String indexPage(Model model){
        return "index";
    }

    @GetMapping("/about")
    public String aboutPage(Model model){return "about";
    }

    @GetMapping("/greeting/Dan")
    public String greetingPage(Model model){
        model.addAttribute("name", "Dan");
        return "greeting";
    }

    @GetMapping("/greeting/Alex")
    public String greetingAlexPage(Model model){
        model.addAttribute("name", "Alex");
        return "greeting";
    }
}
