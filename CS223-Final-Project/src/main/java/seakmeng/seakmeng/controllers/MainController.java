package seakmeng.seakmeng.controllers;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;


@Controller
public class MainController {

    @GetMapping("./")
    public String indexPage(Model model) {
        return "index";
    }

    @GetMapping("/getAllTasks")
    public String helloPage(Model model) {
        return "hello";
    }
}
