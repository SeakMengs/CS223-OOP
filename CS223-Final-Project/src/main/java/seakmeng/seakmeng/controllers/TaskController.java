package seakmeng.seakmeng.controllers;

import seakmeng.seakmeng.models.*;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.PathVariable;
import seakmeng.seakmeng.repositories.TaskRepository;

@Controller
public class TaskController {

    @Autowired
    private TaskRepository taskRepository;

    @GetMapping("/tasks")
    public String getAllTasks(Model model) {
        Iterable<Task> tasks = taskRepository.findAll();
        model.addAttribute("tasks", tasks);
        return "tasks";
    }

    @PostMapping("/tasks/add")
    public String addNewTask(@RequestParam String task_date, @RequestParam String task_name,
            @RequestParam String task_description, @RequestParam String task_status, Model model) {
        Task task = new Task(task_date, task_name, task_description, task_status);
        taskRepository.save(task);
        return ("redirect:/tasks");
    }

    @GetMapping("taskadd")
    public String addTask(Model model) {
        return ("taskadd");
    }

    @GetMapping("taskedit")
    public String editTaskk(Model model) {
        return ("taskedit");
    }

    @GetMapping("/task{id}/edit")
    public String editTaskPage(@PathVariable(value = "id") Long id, Model model) {
        if (!taskRepository.existsById(id)) {
            return "redirect:/tasks";
        }
        Task task = taskRepository.findById(id).orElseThrow();
        model.addAttribute("task", task);
        return "taskedit";
    }

    @PostMapping("/task{id}/edit")
    public String editTask(@RequestParam(value = "id") Long id, @RequestParam String task_date,
            @RequestParam String task_name,
            @RequestParam String task_description, @RequestParam String task_status, Model model) {
            if(!taskRepository.existsById(id)){
                return "redirect:/tasks";
            }
            Task task = taskRepository.findById(id).orElseThrow();
            task.setTask_date(task_date);
            task.setTask_name(task_name);
            task.setTask_description(task_description);
            task.setTask_status(task_status);
            
            taskRepository.save(task);
            return "redirect:/tasks";
    }

    @PostMapping("/task{id}/delete") 
    public String deleteTask(@PathVariable(value = "id") Long id, Model model) {
        if(!taskRepository.existsById(id)){
            return "redirect:/tasks";
        }

        Task task = taskRepository.findById(id).orElseThrow();
        taskRepository.delete(task);
        return "redirect:/tasks";
    }
}
